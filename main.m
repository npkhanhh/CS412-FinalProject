%% Load data
% load folder list
pathSeparator = '';
if ispc
    pathSeparator = '\';
elseif isunix
    pathSeparator = '/';
end

fileID = fopen(['data' pathSeparator 'list.txt']); % The ID of the file

list = textscan(fileID, '%s');
list = list{1, 1};

% load first folder
folderName = list{1, 1};
files = dir(['data' pathSeparator folderName pathSeparator '*.jpg']);
filesName = {files.name};
filesNum = numel(filesName);
data = cell(filesNum, 1);

for i=1:filesNum
    data{i} = imread(['data' pathSeparator folderName pathSeparator filesName{i}]);
end


imshow(data{1});
h = imrect;

fclose(fileID);
