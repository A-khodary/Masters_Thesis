/*AccelerometerI2C.h*/

#ifndef ACCELEROMETERI2C_H
#define ACCELEROMETERI2C_H

#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPiI2C.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <vector>

using namespace std;

class AccelerometerI2C {
	public:
		AccelerometerI2C(int devNum);
		bool data_raw(int &_x, int &_y, int &_z);
		bool data(double &_x, double &_y, double &_z);
		bool isInitialized();
		
	private:
		bool initialized;
		int fd_I2C;
};
#endif