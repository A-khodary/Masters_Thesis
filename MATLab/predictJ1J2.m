function [ J1 , J2] = predictJ1J2( acc , Rmod )

        setGlobalAcc1(acc);
        setGlobalRmod(Rmod);

        % Algorithm Setup
        options = optimoptions('fsolve','Display','iter');

        % Determine Joints One and Two
        x0 =[1,1];
        [x,fval] = fsolve(@myFunction12mod,x0,options);
        J1 = x(1,1);
        J2 = x(1,2);
%     
%     
%         acc1_Norm = rotz(-0.04)*roty(-0.07)*rotx(0.04)*acc1_Norm;
%         j2 = atan2(acc1_Norm(1,1),acc1_Norm(3,1));
%         s = acc1_Norm(1,1)/sin(j2);
%         c = -1*acc1_Norm(2,1);
%         j1 = atan2(s,c);
%         setGlobalJ1(j1);
%         setGlobalJ2(j2);
%     %    setGlobalJ1(joints(1,1));
%     %    setGlobalJ2(joints(1,2));
% 
%         % Determine Joints Three and Four
%         x0 =[0,0];
%         [x,fval] = fsolve(@myFunction34,x0,options2)
%         j3 = x(1,1);
%         j4 = x(1,2);
%          setGlobalJ3(j3);
%          setGlobalJ4(j4)

end

