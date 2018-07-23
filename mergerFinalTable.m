%% This script merges individual resultsTable into final_table, removes
% empty rows, sorts and saves final_result

clear
lista = dir('results_from_group_run\result_*.mat');
load([lista(1).folder filesep lista(1).name]);
resultsTable.id{1} = {};
resultsTable.names{1} = {};
resultsTable.final{1} = {};
final_table = resultsTable;
for i = 1:size(lista,1)
   load([lista(i).folder filesep lista(i).name]);
   b = find(~cellfun('isempty',resultsTable.id));
    final_table(b,:) = resultsTable(b,:);
end

listb = dir('new_result\result_*.mat');
resultsTable.id{1} = {};
resultsTable.names{1} = {};
resultsTable.final{1} = {};
for i = 1:size(listb,1)
    load([listb(i).folder filesep listb(i).name]);
    id = strsplit(listb(i).name,'_');
    id = id{2};
    id = str2num(id(1:3));
    if isempty(final_table.id{id})
         final_table(id,:) = resultsTable(1,:);
    else
        warning('not match')
    end
end

% Removes row 8 and 112 (empty because images deleted from Gt_Data but
% actual image still exists in big_images

final_table(8,:) = [];
final_table(111,:) = [];

% sort and save
final_table = sortrows(final_table,'id','ascend');
save('final_table.mat','final_table');