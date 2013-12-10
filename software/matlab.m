for i=1:29
img = imread(list(i).name);
name = strcat(int2str(i), '.csv');
csvwrite(name, img);
end
