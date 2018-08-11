%% This function will seprate out the scores in final_table and add box
% size score
clear
load final_table.mat

if ispc
    masterPath = 'D:\Deep\repos\pollen-master';
    addpath(genpath(masterPath));
else
    error('Only compatible with PC yet');
end

load big_image\GT_data.mat;

for i = 1:size(final_table,1)
    
    
    [Row, Column, ~]=size(imread(GT_data.imageFilename{i}));
    box = GT_data.bbox{i};
    
    
    %Perform clipping on box / GT -Not required though
    high_c = find(box(:,1)+box(:,3) >= Column);
    box(high_c,3) = Column - box(high_c,1);
    
    high_r = find(box(:,2)+box(:,4) >= Row);
    box(high_r,4) = Row - box(high_r,2);
    
    
    % Remove negative/0 H W box--sanity check
    box(box(:,3)<1,:) = [];
    box(box(:,4)<1,:) = [];
    
    
    final = final_table.final{i};
    perct_covered = cell(size(final,1),1);
    grain_cut = cell(size(final,1),1);
    avg_box_w = cell(size(final,1),1);
    min_box_w = cell(size(final,1),1);
    max_box_w = cell(size(final,1),1);
    avg_box_h = cell(size(final,1),1);
    min_box_h = cell(size(final,1),1);
    max_box_h = cell(size(final,1),1);
    overlap_mean = cell(size(final,1),1);
    final.Properties.VariableNames{1}='NumBoxes';
    for j = 1:size(final,1)
        
        patchBox = round(final.optimalBboxes{j});
        % clip patchBox larger than I
        
        %special case: if patchBox starts on last X or Y of image, remove it
        % completely so it doesnt end up with 0 W or H
        patchBox( patchBox(:,1) == Column , : ) = [];
        patchBox( patchBox(:,2) == Row , : ) = [];
        
        %Perform clipping on patchBox
        high_c = find(patchBox(:,1)+patchBox(:,3) >= Column);
        patchBox(high_c,3) = Column - patchBox(high_c,1);
        
        high_r = find(patchBox(:,2)+patchBox(:,4) >= Row);
        patchBox(high_r,4) = Row - patchBox(high_r,2);
        
        
        % Remove PatchBox  with H and W less than 100
        patchBox(patchBox(:,3)<100,:) = [];
        patchBox(patchBox(:,4)<100,:) = [];
        
        % BBOx Overlap
        iou = bboxOverlapRatio(patchBox,box,'Min');
        
        %remove empty patchBox
        emptyPatchBox = max(iou,[],2) == 0;
        
        patchBox(emptyPatchBox,:) = [];
        
        % Delete small patchBox completely inside bigger PB
        param_overlap_iou = visionBboxIntersectByMin(patchBox,patchBox);
        param_overlap_iou = triu(param_overlap_iou, 1);
        [a b]= find(param_overlap_iou==1);
        del = [];
        for k = 1 : numel(a)
            if patchBox(a(k),1)>patchBox(b(k),1)
                del = [del; a];
            end
        end
        patchBox(del,:) = [];
        
        s = score_func(Row, Column, box,1, patchBox);
        
        final.optimalBboxes{j} = patchBox;
        perct_covered{j} = s(1);
        grain_cut{j} = s(2);
        avg_box_w{j} = mean(patchBox(:,3));
        min_box_w{j} = min(patchBox(:,3));
        max_box_w{j} = max(patchBox(:,3));
        avg_box_h{j} = mean(patchBox(:,4));
        min_box_h{j} = min(patchBox(:,4));
        max_box_h{j} = max(patchBox(:,4));        
        
        param_overlap_iou = visionBboxIntersectByMin(patchBox,patchBox);
        param_overlap_iou = triu(param_overlap_iou, 1);
        nelms = (size(param_overlap_iou, 1)-1:-1:1)';
        t = sum(param_overlap_iou(1:end-1,:), 2) ./ nelms;
        overlap_mean{j} = mean(t);
        %gt_param_iou = visionBboxIntersectByMin(gt,params);
        
    end
    row_names = {'NumBoxes';'optimalBboxes';'perct_covered';'grain_cut'; ...
        'avg_box_w';'min_box_w';'max_box_w';'avg_box_h';'min_box_h';'max_box_h';'overlap_mean';};
    final  = table(final.NumBoxes,final.optimalBboxes,perct_covered, ...
        grain_cut,avg_box_w,min_box_w,max_box_w,avg_box_h,min_box_h,max_box_h,overlap_mean, ...
        'VariableNames',row_names);
    final_table.final{i}=final;
    clear final
end
save('final_pso_table.mat','final_table');