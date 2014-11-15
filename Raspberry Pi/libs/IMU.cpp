/* IMU.c */
#include "IMU.h"

using namespace std;

IMU::IMU()
{
	initialized = false;
}


int IMU::initialize()
{

	wiringPiSetup();
	int ID;
	ID = 0x68;
	if((fd_I2C=wiringPiI2CSetup(ID))<0)
		printf("error opening i2c channel\n");
	else
		printf("i2c channel open - IMU\n");
	
	wiringPiI2CWriteReg8(fd_I2C,107,128); 
	sleep(0.1);
	wiringPiI2CWriteReg8(fd_I2C,107,1); 
	sleep(0.1);
	wiringPiI2CWriteReg8(fd_I2C,28,0);
	sleep(0.1);
	
	// char testVal = 0x00;
	// cout << "IMU_fd: " << fd_I2C << endl;
	// for (int i = 0 ; i < 50; i++)
	// {	
		// testVal = wiringPiI2CReadReg8(fd_I2C,i);
		// cout << "reg: " << i << "\tFrom IMU: " << testVal << endl;
	// }
	initialized = 1;
}

void IMU::data(int &_X, int &_Y, int &_Z)
{
	vector<int> acc_raw;
	int X,Y,Z, X_temp,Y_temp,Z_temp;
	X_temp = 0;
	Y_temp = 0;
	Z_temp = 0;
	int setSize = 100;
	
	for(int i = 0; i < setSize; i++)
	{
		sleep(0.01);
		char values[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Read X,Y,Z
		

		if((fd_I2C)>=0)
		{
			values[0] = wiringPiI2CReadReg8(fd_I2C,0x3B);
			values[1] = wiringPiI2CReadReg8(fd_I2C,0x3C);
			values[2] = wiringPiI2CReadReg8(fd_I2C,0x3D);
			values[3] = wiringPiI2CReadReg8(fd_I2C,0x3E);
			values[4] = wiringPiI2CReadReg8(fd_I2C,0x3F);
			values[5] = wiringPiI2CReadReg8(fd_I2C,0x40);
		}
		
		
		X = values[1] << 8 | values[0];
		if(X >= 32768)
		{
			X = X ^ 0xFFFF;
			X = X+1;
			X = X*-1;
		}

		Y = values[3] << 8 | values[2];
		if(Y >= 32768)
		{
			Y = Y ^ 0xFFFF;
			Y = Y+1;
			Y = Y*-1;
		}
		
		Z = values[5] << 8 | values[4];
		if(Z >= 32768)
		{
			Z = Z ^ 0xFFFF;
			Z = Z+1;
			Z = Z*-1;
		}
		
		X_temp = X_temp+X;
		Y_temp = Y_temp+Y;
		Z_temp = Z_temp+Z;
	}
	
	acc_raw.resize(3);
	acc_raw[0] = X_temp/setSize;
	acc_raw[1] = Y_temp/setSize;
	acc_raw[2] = Z_temp/setSize;
	
	_X = acc_raw[0];
	_Y = acc_raw[1];
	_Z = acc_raw[2];
	
}

int IMU::isInitialized()
{
	return initialized;
}