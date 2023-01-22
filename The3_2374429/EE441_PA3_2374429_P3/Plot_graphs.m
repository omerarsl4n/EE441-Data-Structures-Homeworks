x = 1:1:25%%sample matrices
%%
close all;%%BST time case, y datas taken from output.txt
y = [0.0153048, 0.011516, 0.013487, 0.0119606, 0.017504, 0.0172108, 0.0195598, 0.02256, 0.0275643, 0.0286949, 0.0462981, 0.0545979, 0.0581311, 0.0589966, 0.059045, 0.0715519, 0.0781567, 0.0833162, 0.0827656, 0.0857235, 0.0905126, 0.168136, 0.184777, 0.18535, 0.189133]
plot(x,y);
xlabel("Sample Number of Matrices");
ylabel("Average Time(s) to find determinant");
%%
close all; %hash time case y datas taken from output.txt
y = [0.0069247, 0.0054423, 0.0064875, 0.00587065, 0.00695158, 0.00715053, 0.00817389, 0.00947814, 0.01119, 0.0116181, 0.0144026, 0.0160561, 0.0176573, 0.01819, 0.0184198, 0.0210431, 0.0229952, 0.0247846, 0.0251633, 0.0263733, 0.0281685, 0.0406331, 0.0448083, 0.0457535, 0.047431]
plot(x,y);
xlabel("Sample Number of Matrices");
ylabel("Average Time(s) to find determinant");
%%
close all;%%BST memory case y datas taken from output.txt
y = [815, 632, 787, 713, 876, 839, 923, 1065, 1275, 1289, 1446, 1517, 1646, 1641, 1657, 1766, 1838, 1881, 1869, 1922, 1956, 2666, 2825, 2819, 2886];
y = y.*16.241; %% each BST_Node size equal to 16241 byte
plot(x,y);
xlabel("Sample Number of Matrices");
ylabel("Average Memory(kB) to find determinant");
%%
close all;%%hash memory case y datas taken from output.txt
y = [815, 632, 787, 713, 876, 839, 923, 1065, 1275, 1289, 1446, 1517, 1646, 1641, 1657, 1766, 1838, 1881, 1869, 1922, 1956, 2666, 2825, 2819, 2886];
y = y.*16.081;  %% each Hash_Node size equal to 16081 byte
plot(x,y);
xlabel("Sample Number of Matrices");
ylabel("Average Memory(kB) to find determinant");