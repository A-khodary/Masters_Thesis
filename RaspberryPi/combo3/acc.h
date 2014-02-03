/*Acc.h*/

#ifndef ACC_H
#define ACC_H

#include <bcm2835.h>
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

class Acc {
	public:
		Acc(int devNum);
		~Acc();
		int data_raw(int &_x, int &_y, int &_z);
		int data(double &_x, double &_y, double &_z);
		
	private:
		int type,initialized, fd_I2C;
};
#endif