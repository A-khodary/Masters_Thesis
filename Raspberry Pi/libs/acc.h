/*Acc.h*/

#ifndef ACC_H
#define ACC_H

#include <bcm2835.h>
#include <wiringPi.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPiI2C.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <vector>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

class Acc {
	public:
		int initialize(int devNum);
		Acc();
		~Acc();
		void normalize(double &_X, double &_Y, double &_Z);
		int data_raw(int &_x, int &_y, int &_z);
		int data(double &_x, double &_y, double &_z);
		vector<double> acc;
		vector<int> acc_raw;
		int isInitialized();
		int end;
		
	private:
		int dev,initialized, fd_I2C;
		
};
#endif