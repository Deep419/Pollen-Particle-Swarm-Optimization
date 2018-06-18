% function [s,optParams] = pso_test(var)
var = 38;
var = round(var);
dummyData = 0;
numBoxes = var;
warning off
gpuLimit = 1000;
masterPath = fullfile('D:','Deep','repos','master_scripts');
masterPath = fullfile('D:','research','pollen','repos','master_scripts');
if isunix
    masterPath = '/users/dghaghar/research/data/pollen/master_scripts';
end
load([masterPath filesep fullfile('big_image','GT_data.mat')]);
img = imread([masterPath filesep fullfile('big_image','Achillea_millefolium_c_1.tif')]);
gt = GT_data.bbox{1,1};

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
options = optimoptions('particleswarm','Display', 'off', ...
    'SwarmSize',640, 'UseParallel', 1,'OutputFcn',@myfun);
% 'OutputFcn',@myfun

%Left Corner Initialization
params = [repelem(1,numBoxes*2) repelem(gpuLimit,numBoxes*2)];

%Randi init
params = [randi(c,1,numBoxes) randi(r,1,numBoxes) randi(gpuLimit,1,numBoxes*2)];


% tic

func = @(params) score_func(r, c, gt, params);

% figure;
optParams = particleswarm(func, nvars, lb , ub, options);
% toc
optParams = reshape(optParams,[numBoxes 4]);
s = score_func(r, c, gt, optParams);
% color = jet(numBoxes);
% I = insertShape(img,'rectangle',optParams,'color',color*255,'LineWidth',10);
% figure;imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',10));
% end

function stop = myfun(optimValues,state)
if state == 'init'
    figure;
elseif state == 'iter'
    numBoxes = size(optimValues.bestx,2)/4;
    params = reshape(optimValues.bestx,[numBoxes 4]);
    color = jet(numBoxes);
    img = zeros(4240,4172,'uint8');
    imshow(insertShape(img,'rectangle',params,'color',color*255,'LineWidth',5));
%     imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',3));
else
    a=[];
end
stop = false;
end