%%load data
%load folder list
list = textread('data\list.txt', '%s');

%load first folder
folderName = list{1, 1};
files = dir(['data\' folderName '\*.jpg']);
filesName = {files.name};
filesNum = numel(filesName);
data = cell(filesNum, 1);
for i=1:filesNum
    data{i} = imread(['data\' folderName '\' filesName{i}]);
end

imshow(data{1});
h = imrect;