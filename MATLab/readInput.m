function [ imu, acc1, acc2, acc3, acc4, joints ] = readInput( connection , mode)
%READINPUT - reads the broadcasted data from the raspberry pi


    if mode == 0
        fprintf(connection, 'getData');
        data_In = fscanf(connection);
        if 1 ~= isempty(data_In)
            dataIMU = textscan(data_In,'%f',3);
            data = textscan(data_In,'%d',16);
            data2 = textscan(data_In,'%f');

            imu(1,1) = dataIMU{1}(1);
            imu(1,2) = dataIMU{1}(2);
            imu(1,3) = dataIMU{1}(3);
            acc1(1,1) = data{1}(4);
            acc1(1,2) = data{1}(5);
            acc1(1,3) = data{1}(6);
            acc2(1,1) = data{1}(7);
            acc2(1,2) = data{1}(8);
            acc2(1,3) = data{1}(9);
            acc3(1,1) = data{1}(10);
            acc3(1,2) = data{1}(11);
            acc3(1,3) = data{1}(12);
            acc4(1,1) = data{1}(13);
            acc4(1,2) = data{1}(14);
            acc4(1,3) = data{1}(15);

            if data{1}(16) == 1
                joints(1,1) = data2{1}(17);
                joints(1,2) = data2{1}(18);
                joints(1,3) = data2{1}(19);
                joints(1,4) = data2{1}(20);
                joints(1,5) = data2{1}(21);
                joints(1,6) = data2{1}(22); 
                joints(1,7) = data2{1}(23);
            else
                joints(1,1) = 0;
                joints(1,2) = 0;
                joints(1,3) = 0;
                joints(1,4) = 0;
                joints(1,5) = 0;
                joints(1,6) = 0;
                joints(1,7) = 0;
            end
            
        end
    else

        dataIndex = mode;
    
        acc1_raw = csvread('6-acc1OUT.csv');
        acc2_raw = csvread('6-acc2OUT.csv');
        acc3_raw = csvread('6-acc3OUT.csv');
        acc4_raw = csvread('6-acc4OUT.csv');
%         imu_raw = csvread('26-IMU_OUT.csv');
        j = csvread('6-jointOUT.csv');        
        
        
% 
%         imu(1,1) = imu_raw(dataIndex,1);
%         imu(1,2) = imu_raw(dataIndex,2);
%         imu(1,3) = imu_raw(dataIndex,3);
        imu(1,1) = 0;
        imu(1,2) = 0;
        imu(1,3) = 0;
        acc1(1,1) = acc1_raw(dataIndex,1);
        acc1(1,2) = acc1_raw(dataIndex,2);
        acc1(1,3) = acc1_raw(dataIndex,3);
        acc2(1,1) = acc2_raw(dataIndex,1);
        acc2(1,2) = acc2_raw(dataIndex,2);
        acc2(1,3) = acc2_raw(dataIndex,3);
        acc3(1,1) = acc3_raw(dataIndex,1);
        acc3(1,2) = acc3_raw(dataIndex,2);
        acc3(1,3) = acc3_raw(dataIndex,3);
        acc4(1,1) = acc4_raw(dataIndex,1);
        acc4(1,2) = acc4_raw(dataIndex,2);
        acc4(1,3) = acc4_raw(dataIndex,3);
        joints(1,1) = j(dataIndex,1);
        joints(1,2) = j(dataIndex,2);
        joints(1,3) = j(dataIndex,3);
        joints(1,4) = j(dataIndex,4);
        joints(1,5) = j(dataIndex,5);
        joints(1,6) = j(dataIndex,6);
        joints(1,7) = j(dataIndex,7);
    end

end

