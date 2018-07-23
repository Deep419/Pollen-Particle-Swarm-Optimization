function pso_main(index)
fprintf('\n\nIndex %d\n\n',index);
if index>133
    error('Start exceeding 133')
end
clus = parcluster('local');
pool = parpool('local',clus.NumWorkers);
tic
savefile_name = sprintf('result_%03d.mat',index);

warning off

masterPath = fullfile('D:','Deep','repos','master_scripts');
% masterPath = fullfile('D:','research','pollen','master_scripts');
if isunix
    masterPath = '/users/dghaghar/research/data/pollen/master_scripts';
end
setGlobalPath(masterPath);

load(fullfile(masterPath,'big_image','GT_data.mat'));

images = dir(fullfile(masterPath,'big_image','*.tif'));
final = cell(1,1);
names = cell(1,1);
id = cell(1,1);

for i = index
    idx = find(strcmp(['big_image' filesep  images(i).name],GT_data.imageFilename));
    if ~isempty(idx)
        names{1} = images(i).name;
        id{1} = GT_data.id{idx};
        savefile_name = sprintf('result_%03d-id%s.mat',index,id{1});
        fprintf('\nImage #%d : ID %s - %s\n',i,id{1},names{1});
        image_tic = tic;
        final{1} = perform_pso(GT_data(idx,:));
        fprintf('\tCompleted Image #%d in %.f seconds\n',i,toc(image_tic));
        resultsTable = table(id,names,final);
        save(savefile_name,'resultsTable');
    else
        fprintf('\nImage #%d (%s) not found\n',i,images(i).name);
    end
end
resultsTable = table(id,names,final);
fprintf('\n\nScript complete in %.f seconds. Saving results',toc);
save(savefile_name,'resultsTable');
end


function result = perform_pso(GT_data)

imgPath = fullfile(getGlobalPath,GT_data.imageFilename{:});
img = imread(imgPath);
gt = GT_data.bbox{:};

[r,c,~] = size(img);

%% PSO Params
gpuLimit = 1000;
swarmSize = 2000;

%orig_box = ceil(r/1000) * ceil(c/1000);
%numBoxesRange = max(orig_box-10,3):orig_box+10;

skip_idx = 20;
numBoxesRange = 1:size(gt,1)/skip_idx:size(gt,1);
numBoxesRange = round(numBoxesRange);
optimalBboxes = cell(numel(numBoxesRange),1);
scores = cell(numel(numBoxesRange),1);

for n = 1:numel(numBoxesRange)
    numBoxes = numBoxesRange(n);
    clear lb ub nvars init_swarm pts C i randi_w randi_h options params func optParams s
    lb = repelem(1,numBoxes * 4);
    ub = [repelem(c,numBoxes) repelem(r,numBoxes) repelem(gpuLimit,numBoxes*2)];
    nvars = numBoxes * 4;
    init_swarm = zeros(2000,numBoxes*4);
    rng(42)
    
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
        %init_swarm(i,:) = [round(C(:,1)') round(C(:,2)') ones(1,numBoxes*2)];
    end
    
    options = optimoptions('particleswarm','Display', 'off', ...
        'SwarmSize',swarmSize, 'UseParallel', 1,'InitialSwarmMatrix',init_swarm);
    % ,'OutputFcn',@myfun
    
    params = ones(1,numBoxes*4);
    
    func = @(params) score_func(r, c, gt, 0, params);
    fprintf('\t\t %d) %d numBoxes in progress',n,numBoxes);
    pso_tic = tic;
    optParams = particleswarm(func, nvars, lb , ub, options);
    fprintf('\b\b\b\b\b\b\b\b\b\b\bcompleted in %.f seconds\n',toc(pso_tic));
    
    s = score_func(r, c, gt,1, optParams);
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
