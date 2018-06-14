
function s = score_func(r,c, gt, params)
% gt = [20 40 50 60; 300 100 100 75; 10 300 80 110];
img = zeros(r,c,'uint8');
params = reshape(params,[10 4]);
params;
% params = randi(500,4);
% params(:,[1 2]) = round(params(:,[1 2])/2);
% params(:,[3 4]) = round(params(:,[3 4])/5);
scores = zeros(1,5);

s = 0;
% if ~any(params(:)<1)
%weed out bboxes larger than
%     for i = 1:size(params,1)
%         current_box = params(i,:);
%         if (current_box(1) + current_box(3)) > size(img,2)
%             s = 1000;
%             flag = false;
%         end
%         if (current_box(2) + current_box(4)) > size(img,1)
%             s = 1000;
%             flag = false;
%         end
%         if ((current_box(3)/current_box(4)) > 5) || ((current_box(3)/current_box(4)) < .2)
%             s = 1000;
%             flag = false;
%         end
%     end

I = insertShape(img,'rectangle',params(:,:),'color','yellow','LineWidth',10);
imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',10));

%0 Make sure params boxes are inside image
iou_score = bboxOverlapRatio([1 1 size(img,1) size(img,2)],params,'min');

ar_score = ones(1,size(params,1));
for i=1:size(params,1)
    
    current_box = params(i,:);
    ar = min(current_box(3),current_box(4))/max(current_box(3),current_box(4));
%     if ar > 1 %if aspect ratio is MORE than 1, use func 1 (y = 1/8(x) - 1/8)
%         ar_score(i) =(1/8)*(ar) - (1/8);
%     else %if aspect ratio is LESS than 1, use func 2 (y = -5/8(x) + 5/8)
%         ar_score(i) = (-5/8)*(ar) + (5/8);
%     end
    ar_score(i) = (-1/.99)*(ar) + (1/.99);
    %% high score for ar more than 5, less than 0.2, width less than 100 and height less than 100
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
%1 Minimize Proposed box Overlap : range [0 1]
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
s = (.25 * scores(1)) + (.25 * scores(2)) + (.5* scores(3));
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