/*IMU.h*/

#ifndef IMU_H
#define IMU_H

#include <wiringPi.h>
#include <wiringPiI2C.h>
 #include <iostream>
 #include <fstream>
 #include <vector>
 

using namespace std;

class IMU {
	public:
		int initialize();
		IMU();
		void data(int &_X, int &_Y, int &_Z);
		int isInitialized();
		
	private:
		int initialized,fd_I2C;
		
};
#endif