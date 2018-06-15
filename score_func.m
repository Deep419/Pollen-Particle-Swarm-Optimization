function s = score_func(r, c, gt, params)

img = zeros(r,c,'uint8');

params = reshape(params,[16 4]);

scores = zeros(1,5);
s = 0;

% if ~any(params(:)<1)

% color = jet(16);
% I = insertShape(img,'rectangle',params(:,:),'color',color*255,'LineWidth',10);
% imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',10));

%% 1. Make sure params boxes are inside image

iou_score = bboxOverlapRatio([1 1 r c],params,'min');
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

iou_score = 1 - mean(iou_score);
scores(1) = mean([iou_score avg_ar_score]);
%calc area = area(polyshape(bbox2points(params(1,:))));
%calc intersction area = rectint(params(1,:),params(3,:));

%% 2 Minimize Proposed box Overlap : range [0 1]
% for i=1:size(params,1)
%     img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))=img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))+1;
% end
iou_score = bboxOverlapRatio(params,params,'min');
iou_means=[];
for i = 1:size(params,1)
    for j = 1:size(params,1)
        if i<j
            iou_means(i) = mean(iou_score(i,j:end));
            break;
        end
    end
end
scores(2) = mean(iou_means);


%2 Maximize GT Coverage : range [0 1]
iou_score = bboxOverlapRatio(gt,params,'min');
max_row_wise = max(iou_score,[],2);
scores(3) = 1 - mean(max_row_wise);


%3 Minimize Grain Cut : range [0 1]


scores(4) = 0;
%4 Maximize Box Size : range [0 1]

scores(5) = 0;
s = (0.25 * scores(1)) + (.25 * scores(2)) + (.5* scores(3));
end





%end


% function [avgObjScore] = morphFunction (regionDataGT, arrayOfImages, paramTest)
%
% objFScore = zeros(1,size(arrayOfImages,3));
% scoreIndex = 1;
% for i = 1:size(arrayOfImages,3)
%     newBinaryImage = arrayOfImages(:,:,i);
%
%     % Morph functions: - see methods.txt for list of morph algorithms
%     if paramTest(1) > 0
%         newBinaryImage = bwareaopen(newBinaryImage, round(paramTest(1)));
%     end
%
%     if paramTest(2) > 0
%         newBinaryImage = bwmorph(newBinaryImage, 'majority', round(paramTest(2)));
%     end
%     %newBinaryImage = bwareaopen(newBinaryImage, round(paramTest(5)));
%     %newBinaryImage = imdilate(newBinaryImage, strel('disk', round(paramTest(6))));
%     if paramTest(3) > 0
%         newBinaryImage = imclose(newBinaryImage, strel('disk', round(paramTest(3))));
%     end
%     if paramTest(4) > 0
%         newBinaryImage = bwareaopen(newBinaryImage, round(paramTest(4)));
%     end
%
%     regionDataGT2 = regionDataGT(:,i);
%
%     objFScore(scoreIndex) = regionCompare (newBinaryImage, regionDataGT2);
%
%     scoreIndex = scoreIndex + 1;
% end
%
% avgObjScore = sum(objFScore)/numel(objFScore);