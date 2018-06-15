function s = score_func(r, c, gt, params)
warning off
numBoxes = numel(params) / 4;

if 0
    numBoxes = 4;
    r = 500;
    c = 500;
    gt = [20 40 50 60; 300 100 100 75; 10 300 80 110];
    gpuLimit = 200;
    params = [repelem(1,numBoxes*2) repelem(gpuLimit,numBoxes*2)];
    params = [repelem(1,numBoxes*2) repelem(gpuLimit,numBoxes*2)];
end


img = zeros(r,c,'uint8');

params = reshape(params,[numBoxes 4]);

scores = zeros(1,5);
s = 0;

% color = jet(numBoxes);
% I = insertShape(img,'rectangle',params,'color',color*255,'LineWidth',3);
% imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',3));

%% 1. Make sure params boxes are inside image

inside_score = bboxOverlapRatio([1 1 r c],params,'min');
inside_score = 1 - mean(inside_score);

ar_score = ones(1,size(params,1));

for i=1:size(params,1)    
    current_box = params(i,:);
    ar = min(current_box(3),current_box(4))/max(current_box(3),current_box(4));
    ar_score(i) = (-1/.99)*(ar) + (1/.99);
    % high score for ar more than 5, less than 0.2, width less than 100 and height less than 100
%     if ar > 5 || ar < 0.2 || 
    if current_box(3) < 100 || current_box(4) < 100
        ar_score(i) = 10;
    end
end
avg_ar_score = mean(ar_score);

scores(1) = mean([inside_score avg_ar_score]);

%calc area = area(polyshape(bbox2points(params(1,:))));
%calc intersction area = rectint(params(1,:),params(3,:));

%% 2 Minimize Proposed box Overlap : range [0 1]
% for i=1:size(params,1)
%     img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))=img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))+1;
% end
param_overlap_iou = bboxOverlapRatio(params,params,'min');
param_overlap_means=[];
for i = 1:size(params,1)
    for j = 1:size(params,1)
        if i<j
            param_overlap_means(i) = mean(param_overlap_iou(i,j:end));
            break;
        end
    end
end

scores(2) = mean(param_overlap_means);

%% 3 Maximize GT Coverage : range [0 1]
gt_param_iou = bboxOverlapRatio(gt,params,'min');
max_row_wise = max(gt_param_iou,[],2);

scores(3) = 1 - mean(max_row_wise);

%% 4 Minimize Grain Cut : range [0 1]

scores(4) = 0;

%% 5 Maximize Box Size : range [0 1]

scores(5) = 0;
s = (0.25 * scores(1)) + (.25 * scores(2)) + (.5* scores(3));
end