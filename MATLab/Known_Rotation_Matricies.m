% Known Rotation Matricies

syms theta1 theta2 theta3 theta4

%RG0 = [-1 0 0; 0 -1 0; 0 0 1];
RG0 = [1 0 0; 0 1 0; 0 0 1];
R01 = [cos(theta1) -sin(theta1) 0; 0 0 1; -sin(theta1) -cos(theta1) 0];
R12 = [cos(theta2) -sin(theta2) 0; 0 0 -1; sin(theta2) cos(theta2) 0];
R02 = R01 * R12;
R2A_1 = [0 0 -1 ; 1 0 0; 0 -1 0];


R23 = [cos(theta3) -sin(theta3) 0; 0 0 1; -sin(theta3) -cos(theta3) 0];
R34 = [cos(theta4) -sin(theta4) 0; 0 0 -1; sin(theta4) cos(theta4) 0];
R24 = R23 * R34;
%R4A = [0 -1 0; 0 0 1; -1 0 0];
R4A_2 = [0 0 1; 0 1 0; -1 0 0];

%M1 = [1.5159 0.1516 0.1516; 0.1516 1.5159 0.1516; 0.1516 0.1516 1.5159]
%B1 = [0.5001; 0.5; 0.4999]


% 
% Rmod =[   0.7738   -0.1349    0.2862;
%     0.0138    0.8851   -0.3007;
%    -0.4795    0.1649    0.8103];

% Rmod = [0.9775   -0.0285    0.0085;
%   -0.0153    0.9783   -0.0209;
%   -0.0514   -0.0215    0.9787];

% Rmod = [  0.9297    0.0667   -0.3459;
%    -0.1704    0.9498   -0.2473;
%     0.2853    0.2611    0.8910];

% Rmod =  [ 0.8563    0.0382   -0.5150;
%    -0.0686    0.9968   -0.0401;
%     0.5119    0.0696    0.8562];

% Rmod = [ 0.9966    0.0155    0.0814;
%    -0.0218    0.9968    0.0772;
%    -0.0799   -0.0787    0.9937];

% Rmod = [0.9985   -0.0706    0.0565;
%     0.0748    0.9921   -0.0692;
%    -0.0511    0.0725    0.9960];

%  Rmod = [0.9969    0.0354    0.0698;
%    -0.0409    0.9961    0.0781;
%    -0.0668   -0.0807    0.9945];

Rmod = [ 0.9907   -0.0212    0.1359;
    0.0241    0.9995   -0.0207;
   -0.1355    0.0233    0.9905];
   
%Rmod = eye(3);


Rmod_2 = [0.9968   -0.0164    0.0000;
    0.0402    0.9951    0.0259;
   -0.0009   -0.0098    0.9909];

%Rmod_2 = eye(3);


setGlobalRmod(Rmod);
setGlobalRmod_2(Rmod_2);
R0G = transpose(RG0);
R10 = transpose(R01);
R21 = transpose(R12);
R20 = transpose(R02);
RA_12 = transpose(R2A_1);
R42 = transpose(R24);
RA_24 = transpose(R4A_2);

ZA_1 = RA_12*R20*R0G*[0;0;1];
ZA_2 = RA_24*R42*R20*R0G*[0;0;1];
% 
% acc1Fig = figure;clf
% title('Accelerometer 1')
% xlabel('Data Sets')
% ylabel('Unit Vector Values')
% hold on
% 
% acc2Fig = figure;clf
% title('Accelerometer 2')
% xlabel('Data Sets')
% ylabel('Unit Vector Values')
% hold on
% 
% acc3Fig = figure;clf
% title('Accelerometer 3')
% xlabel('Data Sets')
% ylabel('Unit Vector Values')
% hold on
% 
% acc4Fig = figure;clf
% title('Accelerometer 4')
% xlabel('Data Sets')
% ylabel('Unit Vector Values')
% hold on
% 
% jointFig12 = figure;clf
% title('Joints 1 and 2')
% xlabel('Data Sets')
% ylabel('Angular Rotation (Radians)')
% hold on
% 
% jointFig34 = figure;clf
% title('Joints 3 and 4')
% xlabel('Data Sets')
% ylabel('Angular Rotation (Radians)')
% hold on
% 
% jointFig56 = figure;clf
% title('Joints 5 and 6')
% xlabel('Data Sets')
% ylabel('Angular Rotation (Radians)')
% hold on
% 
% jointFig7 = figure;clf
% title('Joint 7')
% xlabel('Data Sets')
% ylabel('Angular Rotation (Radians)')
% hold on