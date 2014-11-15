#ifndef CALIBRATION_H
#define CALIBRATION_H

/*Calibration.h*/
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "acc.h"

class calibration{
	public:
		calibration();
		~calibration();
		vector<double> read(int devNum);
		vector<int> read_raw(int devNum);
		int read_continuous(int devNum);				
		Acc Acc1, Acc2, Acc3, Acc4;
		
	private:
		int initialized;
		pthread_t	tid;
		pthread_attr_t	attr;
};
#endif