function s = score_func(r, c, gt, verify, params)

numBoxes = numel(params) / 4;

% img = zeros(r,c,'uint8');

params = reshape(params,[numBoxes 4]);

scores = zeros(1,5);
s = 0;

% color = jet(numBoxes);
% I = insertShape(img,'rectangle',params,'color',color*255,'LineWidth',3);
% imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',3));

%% 1. Make sure params boxes are inside image

% inside_score = visionBboxIntersectByMin([1 1 r c],params);
inside_score = bboxOverlapRatio([1 1 r c],params,'Min');

inside_score = 1 - mean(inside_score);

ar_score = ones(1,size(params,1));

for i=1:size(params,1)
    current_box = params(i,:);
    ar = min(current_box(3),current_box(4))/max(current_box(3),current_box(4));
    % Linear Function
    ar_score(i) = (-1/.99)*(ar) + (1/.99);
    
    %Guassian Function 1
%     ar_score(i) = 1.271988*exp(-((ar-(-0.1128002))^2)/(2*0.1626162^2));
    
    %Guassian Function 2
%     ar_score(i) = 1.235046*exp(-((ar-(-0.04674503))^2)/(2*0.07193964^2));
    % high score for ar more than 5, less than 0.2, width less than 100 and height less than 100
    %     if ar > 5 || ar < 0.2 ||
    if current_box(3) < 100 || current_box(4) < 100
        ar_score(i) = 1000;
    end
end
avg_ar_score = mean(ar_score);

scores(1) = (0.9 * inside_score) + (0.1 * avg_ar_score);

%calc area = area(polyshape(bbox2points(params(1,:))));
%calc intersction area = rectint(params(1,:),params(3,:));

%% 2 Minimize Proposed box Overlap : range [0 1]
% for i=1:size(params,1)
%     img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))=img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))+1;
% end

% param_overlap_iou = visionBboxIntersectByMin(params,params);
param_overlap_iou = bboxOverlapRatio(params,params,'Min');
param_overlap_iou = triu(param_overlap_iou, 1);
nelms = (size(param_overlap_iou, 1)-1:-1:1)';
param_overlap_means = sum(param_overlap_iou(1:end-1,:), 2) ./ nelms;

scores(2) = mean(param_overlap_means);

%% 3 Maximize GT Coverage : range [0 1]

% gt_param_iou = visionBboxIntersectByMin(gt,params);
gt_param_iou = bboxOverlapRatio(gt,params,'Min');
max_row_wise = max(gt_param_iou,[],2);

scores(3) = 1 - mean(max_row_wise);

%% 4 Minimize Grain Cut : range [0 1]

cut_mean = mean(gt_param_iou(:));
if cut_mean < (size(gt,1)/(size(gt,1)*numBoxes))
    cut_mean = 100;
end
% if cut_mean ~= 0
%     cut_mean = cut_mean / (size(gt,1)/(size(gt,1)*numBoxes));
% end
scores(4) = cut_mean;

%% 5 Maximize Box Size : range [0 1]

scores(5) = 0;

% s = (.1 * scores(1)) + (.5* scores(2)) + (.2* scores(3)) + (.3 * scores(4));
s = (1 * scores(1)) + (10 * scores(2)) + (2 * scores(3)) + (10 * scores(4));
if verify
    s = zeros(1,2);
    s(1) = numel(find(max_row_wise~=0))/size(gt,1);
    s(2) = mean(max_row_wise(find(max_row_wise~=0)));
end
end