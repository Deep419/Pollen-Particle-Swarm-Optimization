% function [s,optParams] = pso_test(var)
% for j = 2:30
tic
var = 9;
var = round(var);
dummyData = 0;
numBoxes = var;
warning off
gpuLimit = 1200;
swarmSize = 2000;
% masterPath = fullfile('D:','Deep','repos','master_scripts');
masterPath = fullfile('D:','research','pollen','master_scripts');
if isunix
    masterPath = '/users/dghaghar/research/data/pollen/master_scripts';
end
load([masterPath filesep fullfile('big_image','GT_data.mat')]);
img = imread([masterPath filesep fullfile('big_image','Vicia_angustifolia__2_c_1.tif')]);
gt = GT_data.bbox{95,1};

if dummyData
    numBoxes = 4;
    img = zeros(500,500,'uint8');
    gpuLimit = 200;
    gt = [20 40 50 60; 300 100 100 75; 10 300 80 110];
end

[r,c,~] = size(img);

lb = repelem(1,numBoxes * 4);
ub = [repelem(c,numBoxes) repelem(r,numBoxes) repelem(gpuLimit,numBoxes*2)];
nvars = numBoxes * 4;
init_swarm = zeros(1000,numBoxes*4);

%     if j==2
clear C pts
pts(:,1) = gt(:,1)+(gt(:,3)/2);
pts(:,2) = gt(:,2)+(gt(:,4)/2);
[~, C] = kmeans(pts,numBoxes);
for i = 1:swarmSize
    %Left Corner Initialization
%   init_swarm(i,:) = [repelem(1,numBoxes*2) repelem(gpuLimit,numBoxes*2)];
  %randi init
    init_swarm(i,:) = [randi(c,1,numBoxes) randi(r,1,numBoxes) repelem(120,numBoxes*2)];
    %init from previous
%     init_swarm(i,:) = optParams;

%init from kmeans
%         randi_w = randi(gpuLimit,1,numBoxes);
%         randi_h = randi(gpuLimit,1,numBoxes);
%         init_swarm(i,:) = [abs((round(C(:,1)') - (randi_w/2))) abs((round(C(:,2)') - (randi_h/2))) randi_w randi_h]; 
%         init_swarm(i,:) = [round(C(:,1)') round(C(:,2)') ones(1,numBoxes*2)]; 

end

options = optimoptions('particleswarm','Display', 'final', ...
    'SwarmSize',swarmSize, 'UseParallel', 1,'InitialSwarmMatrix',init_swarm,'OutputFcn',@myfun);


params = ones(1,numBoxes*4);%[randi(c,1,numBoxes) randi(r,1,numBoxes) randi(gpuLimit,1,numBoxes*2)];

func = @(params) score_func(r, c, gt, 0, params);

optParams = particleswarm(func, nvars, lb , ub, options);

optParams = reshape(optParams,[numBoxes 4]);
s = score_func(r, c, gt,1, optParams)
color = winter(numBoxes*2)*255;

I = insertShape(img,'rectangle',optParams,'color',color(1:2:end,:),'LineWidth',10);
figure;imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',2));title(num2str(numBoxes));

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