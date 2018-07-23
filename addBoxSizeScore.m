%% This function will seprate out the scores in final_table and add box
% size score 
clear
load final_table.mat

for i = 1:size(final_table,1)    
    final = final_table.final{i};
    perct_covered = cell(size(final,1),1);
    grain_cut = cell(size(final,1),1);
    avg_box_w = cell(size(final,1),1);
    min_box_w = cell(size(final,1),1);
    max_box_w = cell(size(final,1),1);
    avg_box_h = cell(size(final,1),1);    
    min_box_h = cell(size(final,1),1);
    max_box_h = cell(size(final,1),1);
    final.Properties.VariableNames{1}='NumBoxes';
    for j = 1:size(final,1)
        final.optimalBboxes{j}= round(final.optimalBboxes{j});
        perct_covered{j} = final.scores{j}(1);
        grain_cut{j} = final.scores{j}(2);
        avg_box_w{j} = mean(final.optimalBboxes{j}(:,3));
        min_box_w{j} = min(final.optimalBboxes{j}(:,3));
        max_box_w{j} = max(final.optimalBboxes{j}(:,3));
        avg_box_h{j} = mean(final.optimalBboxes{j}(:,4));
        min_box_h{j} = min(final.optimalBboxes{j}(:,4));
        max_box_h{j} = max(final.optimalBboxes{j}(:,4));
    end
    row_names = {'NumBoxes';'optimalBboxes';'perct_covered';'grain_cut'; ...
        'avg_box_w';'min_box_w';'max_box_w';'avg_box_h';'min_box_h';'max_box_h';};
    final  = table(final.NumBoxes,final.optimalBboxes,perct_covered, ...
        grain_cut,avg_box_w,min_box_w,max_box_w,avg_box_h,min_box_h,max_box_h, ...
        'VariableNames',row_names);
    final_table.final{i}=final;
    clear final
end
save('final_table.mat','final_table');