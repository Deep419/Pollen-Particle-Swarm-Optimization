load ../master_scripts/big_image/GT_data.mat
img = imread('../master_scripts/big_image/Achillea_millefolium_c_1.tif');
% img = zeros(500,500,'uint8');
lb = repelem(1,64);%[1,1,1,1,1,1,1,1];
% ub = repelem(500,16);
ub = [repelem(4172,32) repelem(1000,32)];%[4172,4172,4172,4172,1000,1000,1000,1000];

% options = optimoptions(@(params) score_func(I, GT_data.bbox{2,1}));
options = optimoptions('particleswarm','Display', 'iter', ...
    'SwarmSize',640, 'UseParallel', 1);
% options = optimoptions(@(params) score_func(I, GT_data.bbox{2,1}), params);
[r,c,~] = size(img);
GT = [20 40 50 60; 300 100 100 75; 10 300 80 110];
GT = GT_data.bbox{1,1};
% params = ones(1,16)*501;
params = [repelem(1,32) repelem(1000,32)];

tic
func = @(params) score_func(r,c, GT, params);

% figure;
optimalMorphParams = particleswarm(func, 64, lb , ub, options);
toc
fprintf('Optimal morph parameters: '); fprintf('%.2f,',optimalMorphParams);



params = reshape(optimalMorphParams,[16 4]);
color = jet(16);
I = insertShape(img,'rectangle',params,'color',color*255,'LineWidth',10);
figure;imshow(insertShape(I,'rectangle',GT,'color','green','LineWidth',10));