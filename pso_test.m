load ../master_scripts/big_image/GT_data.mat
img = imread('../master_scripts/big_image/Achillea_millefolium_c_1.tif');
% img = zeros(500,500,'uint8');
lb = repelem(1,40);
% ub = repelem(500,16);
ub = repelem(4172,40);

% options = optimoptions(@(params) score_func(I, GT_data.bbox{2,1}));
options = optimoptions('particleswarm','Display', 'iter', ...
    'SwarmSize', 40, 'UseParallel', 0);
% options = optimoptions(@(params) score_func(I, GT_data.bbox{2,1}), params);
[r,c,~] = size(img);
GT = [20 40 50 60; 300 100 100 75; 10 300 80 110];
GT = GT_data.bbox{1,1};
% params = ones(1,16)*501;
params = ones(1,40)*4172;

tic
func = @(params) score_func(r,c, GT, params);


optimalMorphParams = particleswarm(func, 40, lb , ub, options);
toc
fprintf('Optimal morph parameters: '); fprintf('%.2f,',optimalMorphParams);



params = reshape(optimalMorphParams,[10 4]);
I = insertShape(img,'rectangle',params,'color','blue','LineWidth',10);
figure;imshow(insertShape(I,'rectangle',GT,'color','green','LineWidth',10));