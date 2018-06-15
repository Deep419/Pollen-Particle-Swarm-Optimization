lb = 2;
ub = 200;
nvars = 1;
options = optimoptions('particleswarm','Display', 'iter', ...
    'SwarmSize',20, 'UseParallel', 0);

params = ones(1,1)*2;

tic

func = @(params) pso_test(params);

% figure;
opt_numBoxes = particleswarm(func, nvars, lb , ub, options);
toc
opt_numBoxes