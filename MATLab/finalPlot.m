
%m = 621;%7
%m = 686;%6
%m = 1085;%36
%m = 287;%1
%m = 310;%2
%m = 190;%3
%m = 3213;%33
%m = 3994;%22
%m = 2151;%24
%m = 3720/10;%26
%m = 1558;%23
%m =2281;%25
%m =1727;%26 IMU lift


%m =1856;
m =1560;
n = 250;

% Find all windows of type figure, which have an empty FileName attribute, and close.
allPlots = findall(0, 'Type', 'figure', 'FileName', []);
delete(allPlots);


% figure;clf
% hold on;
% plot(listIMUKnown(n:m,1), '--r','DisplayName','listJointsComputed')
% plot(listIMUKnown(n:m,2), ':b','DisplayName','listJointsComputed')
% legend('pitch','roll')
% title('Wheelchair pitch and roll')
% xlabel('Data Sets')
% ylabel('Angular Rotation (Radians)')
% saveas(gcf,'Test-4-IMU','jpg');

%Final Plot
figure;clf
hold on;
plot(listJointsComputed(n:m,1), '--r','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,1), '--k', 'DisplayName','listJointsKnown')
plot(listJointsComputed(n:m,2), ':b','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,2), ':k', 'DisplayName','listJointsKnown')
legend('Joint 1 Computed','Joint 1 Known','Joint 2 Computed','Joint 2 Known')
title('Joints 1 and 2')
xlabel('Data Sets')
ylabel('Angular Rotation (Radians)')
saveas(gcf,'Test-4-J1J2','jpg');

figure;clf
hold on;
plot(listJointsComputed(n:m,3), '--r','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,3), '--k', 'DisplayName','listJointsKnown')
plot(listJointsComputed(n:m,4), ':b','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,4), ':k', 'DisplayName','listJointsKnown')
legend('Joint 3 Computed','Joint 3 Known','Joint 4 Computed','Joint 4 Known')
title('Joints 3 and 4')
xlabel('Data Sets')
ylabel('Angular Rotation (Radians)')
saveas(gcf,'Test-4-J3J4','jpg');

figure;clf
hold on;
plot(listJointsComputed(n:m,5), '--r','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,5), '--k', 'DisplayName','listJointsKnown')
plot(listJointsComputed(n:m,6), ':b','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,6), ':k', 'DisplayName','listJointsKnown')
legend('Joint 5 Computed','Joint 5 Known','Joint 6 Computed','Joint 6 Known')
title('Joints 5 and 6')
xlabel('Data Sets')
ylabel('Angular Rotation (Radians)')
saveas(gcf,'Test-4-J5J6','jpg');

figure;clf
hold on;
plot(listJointsComputed(n:m,7), '--r','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,7), '--k', 'DisplayName','listJointsKnown')
legend('Joint 7 Computed','Joint 7 Known')
title('Joint 7')
xlabel('Data Sets')
ylabel('Angular Rotation (Radians)')
saveas(gcf,'Test-4-J7','jpg');



figure;clf
hold on
plot(listAcc1Computed(n:m,1), 'k--')
plot(listAcc1Known(n:m,1), 'r--')
plot(listAcc1Computed(n:m,2), 'k:')
plot(listAcc1Known(n:m,2), 'g:')
plot(listAcc1Computed(n:m,3), 'k-.')
plot(listAcc1Known(n:m,3), 'b-.')
legend('X-Axis Computed','X-Axis Known','Y-Axis Computed','Y-Axis Known','Z-Axis Computed','Z-Axis Known')
title('Accelerometer 1')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')

figure;clf
hold on
plot(listAcc2Computed(n:m,1), 'k--')
plot(listAcc2Known(n:m,1), 'r--')
plot(listAcc2Computed(n:m,2), 'k:')
plot(listAcc2Known(n:m,2), 'g:')
plot(listAcc2Computed(n:m,3), 'k-.')
plot(listAcc2Known(n:m,3), 'b-.')
legend('X-Axis Computed','X-Axis Known','Y-Axis Computed','Y-Axis Known','Z-Axis Computed','Z-Axis Known')
title('Accelerometer 2')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')

figure;clf
hold on
plot(listAcc3Computed(n:m,1), 'k--')
plot(listAcc3Known(n:m,1), 'r--')
plot(listAcc3Computed(n:m,2), 'k:')
plot(listAcc3Known(n:m,2), 'g:')
plot(listAcc3Computed(n:m,3), 'k-.')
plot(listAcc3Known(n:m,3), 'b-.')
legend('X-Axis Computed','X-Axis Known','Y-Axis Computed','Y-Axis Known','Z-Axis Computed','Z-Axis Known')
title('Accelerometer 3')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')

figure;clf
hold on
plot(listAcc4Computed(n:m,1), 'k--')
plot(listAcc4Known(n:m,1), 'r--')
plot(listAcc4Computed(n:m,2), 'k:')
plot(listAcc4Known(n:m,2), 'g:')
plot(listAcc4Computed(n:m,3), 'k-.')
plot(listAcc4Known(n:m,3), 'b-.')
legend('X-Axis Computed','X-Axis Known','Y-Axis Computed','Y-Axis Known','Z-Axis Computed','Z-Axis Known')
title('Accelerometer 4')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')



figure;clf
hold on
plot(listAcc1Known(n:m,1), 'r--')
plot(listAcc1Known(n:m,2), 'g--')
plot(listAcc1Known(n:m,3), 'b--')
legend('X-Axis','Y-Axis','Z-Axis')
title('Accelerometer 1')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')
saveas(gcf,'Test-4-Acc1','jpg');

figure;clf
hold on
plot(listAcc2Known(n:m,1), 'r--')
plot(listAcc2Known(n:m,2), 'g--')
plot(listAcc2Known(n:m,3), 'b--')
legend('X-Axis','Y-Axis','Z-Axis')
title('Accelerometer 2')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')
saveas(gcf,'Test-4-Acc2','jpg');

figure;clf
hold on
plot(listAcc3Known(n:m,1), 'r--')
plot(listAcc3Known(n:m,2), 'g--')
plot(listAcc3Known(n:m,3), 'b--')
legend('X-Axis','Y-Axis','Z-Axis')
title('Accelerometer 3')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')
saveas(gcf,'Test-4-Acc3','jpg');

figure;clf
hold on
plot(listAcc4Known(n:m,1), 'r--')
plot(listAcc4Known(n:m,2), 'g--')
plot(listAcc4Known(n:m,3), 'b--')
legend('X-Axis','Y-Axis','Z-Axis')
title('Accelerometer 4')
xlabel('Data Sets')
ylabel('Unit Vector Magnitudes')
saveas(gcf,'Test-4-Acc4','jpg');



figure;clf
hold on
plot(listJointsComputed(n:m,1), '--r','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,1), '--k', 'DisplayName','listJointsKnown')
title('Joints 1 through 4')
xlabel('Data Sets')
ylabel('Angular Rotation (Radians)')
plot(listJointsComputed(n:m,2), 'g','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,2), 'k', 'DisplayName','listJointsKnown')
plot(listJointsComputed(n:m,3), '-.b','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,3), '-.k', 'DisplayName','listJointsKnown')
plot(listJointsComputed(n:m,4), '-c','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,4), '-k', 'DisplayName','listJointsKnown')
legend('Joint 1 Computed','Joint 1 Known','Joint 2 Computed','Joint 2 Known',...
    'Joint 3 Computed','Joint 3 Known','Joint 4 Computed','Joint 4 Known')
saveas(gcf,'Test-4-J1J2J3J4','jpg');


figure;clf
plot(listJointsComputed(n:m,5), '--r','DisplayName','listJointsComputed')
hold on
plot(listJointsKnown(n:m,5), '--k', 'DisplayName','listJointsKnown')
title('Joints 5 through 7')
xlabel('Data Sets')
ylabel('Angular Rotation (Radians)')
plot(listJointsComputed(n:m,6), 'g','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,6), 'k', 'DisplayName','listJointsKnown')
plot(listJointsComputed(n:m,7), '-.b','DisplayName','listJointsComputed')
plot(listJointsKnown(n:m,7), '-.k', 'DisplayName','listJointsKnown')
legend('Joint 5 Computed','Joint 5 Known','Joint 6 Computed','Joint 6 Known',...
    'Joint 7 Computed','Joint 7 Known')
saveas(gcf,'Test-4-J5J6J7','jpg');

