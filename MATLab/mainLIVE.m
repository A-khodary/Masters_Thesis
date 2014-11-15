
clear;

% Find all windows of type figure, which have an empty FileName attribute.
allPlots = findall(0, 'Type', 'figure', 'FileName', []);
% Close.
delete(allPlots);

Known_Rotation_Matricies;

u = udp('192.168.1.103',21234);
fopen(u);

m = 109;

listAcc1Known = zeros(m,3);
listAcc1Computed = zeros(m,3);
listAcc2Known = zeros(m,3);
listAcc2Computed = zeros(m,3);
listAcc3Known = zeros(m,3);
listAcc3Computed = zeros(m,3);
listAcc4Known = zeros(m,3);
listAcc4Computed = zeros(m,3);
listJointsKnown = zeros(m,7);
listJointsComputed = zeros(m,7);
acc1_Norm = zeros(1,3);
acc2_Norm = zeros(1,3);
acc3_Norm = zeros(1,3);
acc4_Norm = zeros(1,3);
a1 = zeros(3,1);
a2 = zeros(3,1);
a3 = zeros(3,1);
a4 = zeros(3,1);
j1 = 0;
j2 = 0;
j3 = 0;
j4 = 0;
j5 = 0;
j6 = 0;
i = 1;

listIndex = 0;

%for f=1:1,
%for g=2:m,
while true,
%    i = i + 1
%i = g;
listIndex = listIndex+1

    % [acc1, acc2, acc3, acc4, joints] = readInput(u,i);
       [acc1, acc2, acc3, acc4, joints] = readInput(u,0);

        acc1_Norm = invertVector(Normalize(acc1(1,1:3)));
        acc2_Norm = invertVector(Normalize(acc2(1,1:3)));
        acc3_Norm = invertVector(Normalize(acc3(1,1:3)));
        acc4_Norm = invertVector(Normalize(acc4(1,1:3)));
        
        a1 = findAcc1(joints(1,1), joints(1,2));
        a2 = findAcc2(joints(1,1), joints(1,2), joints(1,3), joints(1,4));
        a3 = findAcc3(joints(1,1), joints(1,2), joints(1,3), joints(1,4), joints(1,5), joints(1,6));
        a4 = findAcc4(joints(1,1), joints(1,2), joints(1,3), joints(1,4), joints(1,5), joints(1,6), joints(1,7));

        [j1,j2] = determineJ1J2_knowns(acc1_Norm, joints(1,1), joints(1,2));
        [j3,j4] = determineJ3J4_knowns(joints(1,1), joints(1,2), acc2_Norm, joints(1,3), joints(1,4));
        %[j3,j4] = determineJ3J4_knowns(j1, j2, acc2_Norm, joints(1,3), joints(1,4));
        [j5,j6] = determineJ5J6_knowns(joints(1,1), joints(1,2),joints(1,3), joints(1,4), acc3_Norm, joints(1,5), joints(1,6));
        %[j5,j6] = determineJ5J6_knowns(j1, j2, j3, j4, acc3_Norm, joints(1,5), joints(1,6));

        if j1>3.2 || j2>3.2 || j3>3.2 || j4>3.2 || j5>3.2 || j6>3.2 || j1<-3.2 || j2<-3.2 || j3<-3.2 || j4<-3.2 || j5<-3.2 || j6<-3.2,
%        if j1>3.2 || j2>3.2 || j3>3.2 || j4>3.2 || j5>3.2 || j6>3.2 || j1<-3.2 || j2<-3.2 || j3<-3.2 || j4<-3.2 || j5<-3.2 || j6<-3.2 || listIndex == 14 || listIndex == 24 || listIndex == 25 || listIndex == 87 ,
            prev = listIndex-1;
            listAcc1Known(listIndex,1:3) = listAcc1Known(prev,1:3);
            listAcc1Computed(listIndex,1:3) = listAcc1Computed(prev,1:3);
            listAcc2Known(listIndex,1:3) = listAcc2Known(prev,1:3);
            listAcc2Computed(listIndex,1:3) = listAcc2Computed(prev,1:3);
            listAcc3Known(listIndex,1:3) = listAcc3Known(prev,1:3);
            listAcc3Computed(listIndex,1:3) = listAcc3Computed(prev,1:3);
            listAcc4Known(listIndex,1:3) = listAcc4Known(prev,1:3);
            listAcc4Computed(listIndex,1:3) = listAcc4Computed(prev,1:3);
            listJointsKnown(listIndex,1:7) = listJointsKnown(prev,1:7);
            listJointsComputed(listIndex,1:7) = listJointsComputed(prev,1:7);
            
            updatePlot;
        else
            listJointsKnown(listIndex,1:7) = joints(1,1:7);
            listJointsComputed(listIndex,1) = double(j1);
            listJointsComputed(listIndex,2) = double(j2);
            listJointsComputed(listIndex,3) = double(j3);
            listJointsComputed(listIndex,4) = double(j4);
            listJointsComputed(listIndex,5) = double(j5);
            listJointsComputed(listIndex,6) = double(j6);

            listAcc1Known(listIndex,1) = acc1_Norm(1,1);
            listAcc1Known(listIndex,2) = acc1_Norm(2,1);
            listAcc1Known(listIndex,3) = acc1_Norm(3,1);
            listAcc1Computed(listIndex,1) = a1(1,1);
            listAcc1Computed(listIndex,2) = a1(2,1);
            listAcc1Computed(listIndex,3) = a1(3,1);
            
            listAcc2Known(listIndex,1) = acc2_Norm(1,1);
            listAcc2Known(listIndex,2) = acc2_Norm(2,1);
            listAcc2Known(listIndex,3) = acc2_Norm(3,1);
            listAcc2Computed(listIndex,1) = a2(1,1);
            listAcc2Computed(listIndex,2) = a2(2,1);
            listAcc2Computed(listIndex,3) = a2(3,1);
            
            listAcc3Known(listIndex,1) = acc3_Norm(1,1);
            listAcc3Known(listIndex,2) = acc3_Norm(2,1);
            listAcc3Known(listIndex,3) = acc3_Norm(3,1);
            listAcc3Computed(listIndex,1) = a3(1,1);
            listAcc3Computed(listIndex,2) = a3(2,1);
            listAcc3Computed(listIndex,3) = a3(3,1);
            
            listAcc4Known(listIndex,1) = acc4_Norm(1,1);
            listAcc4Known(listIndex,2) = acc4_Norm(2,1);
            listAcc4Known(listIndex,3) = acc4_Norm(3,1);
            listAcc4Computed(listIndex,1) = a4(1,1);
            listAcc4Computed(listIndex,2) = a4(2,1);
            listAcc4Computed(listIndex,3) = a4(3,1);

            updatePlot;
        end
end


finalPlot;

fclose(u);