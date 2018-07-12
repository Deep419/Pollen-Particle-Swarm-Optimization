%Version 1 : max(orig_box-10,3):orig_box+10 + Kmeans randinit with rand H W
delete(gcp('nocreate'))
clus = parcluster('local');
pool = parpool('local',clus.NumWorkers);

warning off

masterPath = fullfile('D:','Deep','repos','master_scripts');
% masterPath = fullfile('D:','research','pollen','master_scripts');
if isunix
    masterPath = '/users/dghaghar/research/data/pollen/master_scripts';
end
setGlobalPath(masterPath);

load(fullfile(masterPath,'big_image','GT_data.mat'));

images = dir(fullfile(masterPath,'big_image','*.tif'));
final = cell(size(images,1),1);
names = cell(size(images,1),1);
for i = 1:size(images,1)
    idx = find(strcmp(['big_image' filesep  images(i).name],GT_data.imageFilename));
    if ~isempty(idx)
        fprintf('\nImage #%d',i);
        names{i} = images(i).name;
        tic
        final{i} = perform_pso(GT_data(idx,:));
        fprintf('- completed in %.f seconds',toc);
    else
        warning('Image Not found.');
    end
end
resultsTable = table(names,final);
save('resultsTable.mat','resultsTable');

function result = perform_pso(GT_data)

imgPath = fullfile(getGlobalPath,GT_data.imageFilename{:});
img = imread(imgPath);
gt = GT_data.bbox{:};

[r,c,~] = size(img);

%% PSO Params
gpuLimit = 1000;
swarmSize = 2000;

orig_box = ceil(r/1000) * ceil(c/1000);
numBoxesRange = max(orig_box-10,3):orig_box+10;
if orig_box > size(gt,1)
    temp = round(size(gt,1)/20);
    numBoxesRange = 10:temp:size(gt,1);
end

optimalBboxes = cell(numel(numBoxesRange),1);
scores = cell(numel(numBoxesRange),1);

for n = 1:numel(numBoxesRange)
    numBoxes = numBoxesRange(n);
    clear lb ub nvars init_swarm pts C i
    lb = repelem(1,numBoxes * 4);
    ub = [repelem(c,numBoxes) repelem(r,numBoxes) repelem(gpuLimit,numBoxes*2)];
    nvars = numBoxes * 4;
    init_swarm = zeros(1000,numBoxes*4);
       
    % K-Means init
    pts(:,1) = gt(:,1)+(gt(:,3)/2);
    pts(:,2) = gt(:,2)+(gt(:,4)/2);
    [~, C] = kmeans(pts,numBoxes);
    for i = 1:swarmSize
        %Left Corner Initialization
        %init_swarm(i,:) = [repelem(1,numBoxes*2) repelem(gpuLimit,numBoxes*2)];
        
        %randi init
        %init_swarm(i,:) = [randi(c,1,numBoxes) randi(r,1,numBoxes) repelem(120,numBoxes*2)];
        %init from previous
        %init_swarm(i,:) = optParams;
        
        %init from kmeans
        randi_w = randi(gpuLimit,1,numBoxes);
        randi_h = randi(gpuLimit,1,numBoxes);
        init_swarm(i,:) = [abs((round(C(:,1)') - (randi_w/2))) abs((round(C(:,2)') - (randi_h/2))) randi_w randi_h];
        %     init_swarm(i,:) = [round(C(:,1)') round(C(:,2)') ones(1,numBoxes*2)];
    end
    
    options = optimoptions('particleswarm','Display', 'iter', ...
        'SwarmSize',swarmSize, 'UseParallel', 1,'InitialSwarmMatrix',init_swarm);
    % ,'OutputFcn',@myfun
    
    params = ones(1,numBoxes*4);
    
    func = @(params) score_func_mex(r, c, gt, 0, params);
    
    optParams = particleswarm(func, nvars, lb , ub, options);
    

    s = score_func_mex(r, c, gt, 1, optParams);
    scores{n,1} = s;
    optimalBboxes{n,1} = reshape(optParams,[numBoxes 4]);

%     color = winter(numBoxes*2)*255;     
%     I = insertShape(img,'rectangle',optParams,'color',color(1:2:end,:),'LineWidth',10);
%     figure;imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',2));title(num2str(numBoxes));
end

    result = table(numBoxesRange',scores,optimalBboxes);

end

function stop = myfun(optimValues,state)
if state == 'init'
    figure;
elseif state == 'iter'
    numBoxes = size(optimValues.bestx,2)/4;
    params = reshape(optimValues.bestx,[numBoxes 4]);
    color = jet(numBoxes);
    img = zeros(2819,2933,'uint8');
    imshow(insertShape(img,'rectangle',params,'color',color*255,'LineWidth',5));
    %     imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',3));
else
    a=[];
end
stop = false;
end

function setGlobalPath(path)
global masterPath
masterPath = path;
end

function r = getGlobalPath
global masterPath
r = masterPath;
end