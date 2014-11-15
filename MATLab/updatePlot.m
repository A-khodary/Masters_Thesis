
% Update Plot Script

figure(acc1Fig);
hold on
plot(listIndex, listAcc1Computed(listIndex,1), 'ko')
plot(listIndex, listAcc1Known(listIndex,1), 'r--o')

plot(listIndex, listAcc1Computed(listIndex,2), 'k*')
plot(listIndex, listAcc1Known(listIndex,2), 'g--*')

plot(listIndex, listAcc1Computed(listIndex,3), 'kd')
plot(listIndex, listAcc1Known(listIndex,3), 'b--d')

% 
figure(acc2Fig);
hold on
plot(listIndex, listAcc2Computed(listIndex,1), 'ko')
plot(listIndex, listAcc2Known(listIndex,1), 'r--o')

plot(listIndex, listAcc2Computed(listIndex,2), 'k*')
plot(listIndex, listAcc2Known(listIndex,2), 'g--*')

plot(listIndex, listAcc2Computed(listIndex,3), 'kd')
plot(listIndex, listAcc2Known(listIndex,3), 'b--d')

figure(acc3Fig);
hold on
plot(listIndex, listAcc3Computed(listIndex,1), 'ko')
plot(listIndex, listAcc3Known(listIndex,1), 'r--o')

plot(listIndex, listAcc3Computed(listIndex,2), 'k*')
plot(listIndex, listAcc3Known(listIndex,2), 'g--*')

plot(listIndex, listAcc3Computed(listIndex,3), 'kd')
plot(listIndex, listAcc3Known(listIndex,3), 'b--d')

figure(acc4Fig);
hold on
plot(listIndex, listAcc4Computed(listIndex,1), 'ko')
plot(listIndex, listAcc4Known(listIndex,1), 'r--o')

plot(listIndex, listAcc4Computed(listIndex,2), 'k*')
plot(listIndex, listAcc4Known(listIndex,2), 'g--*')

plot(listIndex, listAcc4Computed(listIndex,3), 'kd')
plot(listIndex, listAcc4Known(listIndex,3), 'b--d')


figure(jointFig12);
hold on
plot(listIndex, listJointsKnown(listIndex,1), 'ko')
plot(listIndex, listJointsComputed(listIndex,1), 'r--o')

plot(listIndex, listJointsKnown(listIndex,2), 'k*')
plot(listIndex, listJointsComputed(listIndex,2), 'g--*')

figure(jointFig34);
hold on
plot(listIndex, listJointsKnown(listIndex,3), 'kh')
plot(listIndex, listJointsComputed(listIndex,3), 'b--h')

plot(listIndex, listJointsKnown(listIndex,4), 'k+')
plot(listIndex, listJointsComputed(listIndex,4), 'm--+')

figure(jointFig56);
hold on
plot(listIndex, listJointsKnown(listIndex,5), 'ks')
plot(listIndex, listJointsComputed(listIndex,5), 'c--s')

plot(listIndex, listJointsKnown(listIndex,6), 'kp')
plot(listIndex, listJointsComputed(listIndex,6), 'y--p')
% 
figure(jointFig7);
hold on
plot(listIndex, listJointsKnown(listIndex,7), 'k<')
plot(listIndex, listJointsComputed(listIndex,7), 'c--<')
