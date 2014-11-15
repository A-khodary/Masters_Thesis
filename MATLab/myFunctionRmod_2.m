function [ F ] = myFunctionRmod_2( x )

[acc1, acc2, acc3, acc4, joints] = readInput(0,900);
acc2_1 = Normalize(acc2);
J1_1 = joints(1,1);
J2_1 = joints(1,2);
J3_1 = joints(1,3);
J4_1 = joints(1,4);

[acc1, acc2, acc3, acc4, joints] = readInput(0,1500);
acc2_2 = Normalize(acc2);
J1_2 = joints(1,1);
J2_2 = joints(1,2);
J3_2 = joints(1,3);
J4_2 = joints(1,4);

[acc1, acc2, acc3, acc4, joints] = readInput(0,2500);
acc2_3 = Normalize(acc2);
J1_3 = joints(1,1);
J2_3 = joints(1,2);
J3_3 = joints(1,3);
J4_3 = joints(1,4);

[acc1, acc2, acc3, acc4, joints] = readInput(0,3500);
acc2_4 = Normalize(acc2);
J1_4 = joints(1,1);
J2_4 = joints(1,2);
J3_4 = joints(1,3);
J4_4 = joints(1,4);

[acc1, acc2, acc3, acc4, joints] = readInput(0,400);
acc2_5 = Normalize(acc2);
J1_5 = joints(1,1);
J2_5 = joints(1,2);
J3_5 = joints(1,3);
J4_5 = joints(1,4);

[acc1, acc2, acc3, acc4, joints] = readInput(0,2000);
acc2_6 = Normalize(acc2);
J1_6 = joints(1,1);
J2_6 = joints(1,2);
J3_6 = joints(1,3);
J4_6 = joints(1,4);

F = [abs(J3_1-predictJ3(J1_1, J2_1, acc2_1,x))+abs(transpose(x)*x-eye(3))+ abs(J4_1-predictJ4(J1_1, J2_1, acc2_1,x))+abs(transpose(x)*x-eye(3))];
%     abs(J3_2-predictJ3(J1_2, J2_2, acc2_2,x))+abs(transpose(x)*x-eye(3))+ abs(J4_2-predictJ4(J1_2, J2_2, acc2_2,x))+abs(transpose(x)*x-eye(3))];
%     abs(J3_3-predictJ3(J1_3, J2_3, acc2_3,x))+abs(transpose(x)*x-eye(3))+ abs(J4_3-predictJ4(J1_3, J2_3, acc2_3,x))+abs(transpose(x)*x-eye(3));
%     abs(J3_4-predictJ3(J1_4, J2_4, acc2_4,x))+abs(transpose(x)*x-eye(3))+ abs(J4_4-predictJ4(J1_4, J2_4, acc2_4,x))+abs(transpose(x)*x-eye(3))];
%     abs(J3_5-predictJ3(J1_5, J2_5, acc2_5,x))+abs(transpose(x)*x-eye(3))+ abs(J4_5-predictJ4(J1_5, J2_5, acc2_5,x))+abs(transpose(x)*x-eye(3));
%     abs(J3_6-predictJ3(J1_6, J2_6, acc2_6,x))+abs(transpose(x)*x-eye(3))+ abs(J4_6-predictJ4(J1_6, J2_6, acc2_6,x))+abs(transpose(x)*x-eye(3))];

end

