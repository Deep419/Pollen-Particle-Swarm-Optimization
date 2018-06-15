dummyData = 0;
numBoxes = 16;

gpuLimit = 1000;
masterPath = fullfile('D:','Deep','repos','master_scripts');
load([masterPath filesep fullfile('big_image','GT_data.mat')]);
img = imread([masterPath filesep fullfile('big_image','Achillea_millefolium_c_1.tif')]);
gt = GT_data.bbox{1,1};

if dummyData
    img = zeros(500,500,'uint8');
    gpuLimit = 200;
    gt = [20 40 50 60; 300 100 100 75; 10 300 80 110];
end

[r,c,~] = size(img);

lb = repelem(1,numBoxes * 4);
ub = [repelem(c,numBoxes) repelem(r,numBoxes) repelem(gpuLimit,numBoxes*2)];
nvars = numBoxes * 4;
options = optimoptions('particleswarm','Display', 'iter', ...
    'SwarmSize',640, 'UseParallel', 1);

params = [repelem(1,numBoxes*2) repelem(gpuLimit,numBoxes*2)];

tic

func = @(params) score_func(r, c, gt, params);

% figure;
optParams = particleswarm(func, nvars, lb , ub, options);
toc
optParams = reshape(optParams,[numBoxes 4]);

color = jet(numBoxes);
I = insertShape(img,'rectangle',optParams,'color',color*255,'LineWidth',10);
figure;imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',10));