parpool('local',32)
s = zeros(1,299);
opt = cell(1,299);
tic
for i = 2:300
    [s(i-1), opt{1,i-1}] = pso_test(i);
    fprintf('\nScore of %.4f with %d variables',s(i-1),i);
end

save('output.mat');
