function [ acc2 ] = findAcc2( j1, j2, j3, j4 )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

%RG0 = [1 0 0; 0 1 0; 0 0 1];
R0G = getGlobalR0G;
R01 = [cos(j1) -sin(j1) 0; 0 0 1; -sin(j1) -cos(j1) 0];
R12 = [cos(j2) -sin(j2) 0; 0 0 -1; sin(j2) cos(j2) 0];
R02 = R01 * R12;
R20 = transpose(R02);
%R0G = transpose(RG0);

R23 = [cos(j3) -sin(j3) 0; 0 0 1; -sin(j3) -cos(j3) 0];
R34 = [cos(j4) -sin(j4) 0; 0 0 -1; sin(j4) cos(j4) 0];
R24 = R23 * R34;
R4A = [0 0 1; 0 1 0;-1 0 0];

R42 = transpose(R24);
RA4 = transpose(R4A);

RAG = RA4*R42*R20*R0G;

%acc2 = RAG*[0;0;1];
%acc2 = RAG*[0;1;0]
%acc2 = RAG*[1;0;0]



%Rmod = eye(3)*roty(0.1);
Rmod = eye(3)*roty(0.12)*rotz(0.08);
acc2 = Rmod*RAG*[0;0;1];


end

