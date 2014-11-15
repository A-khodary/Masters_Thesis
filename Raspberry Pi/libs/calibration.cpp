#include "calibration.h"

using namespace std;

void changemode(int dir);
int kbhit (void);

calibration::calibration()
{
	Acc1.initialize(1);
	Acc2.initialize(2);
	Acc3.initialize(3);
	Acc4.initialize(4);
}

calibration::~calibration()
{

}

int calibration::read_continuous(int devNum)
{
	return 1;
}

vector<double> calibration::read(int devNum)
{
	vector<double> tgt(3);
	
	if(devNum==1)
		Acc1.data(tgt[0],tgt[1],tgt[2]);
	else if(devNum==2)
		Acc2.data(tgt[0],tgt[1],tgt[2]);
	else if(devNum==3)
		Acc3.data(tgt[0],tgt[1],tgt[2]);
	else if(devNum==4)
		Acc4.data(tgt[0],tgt[1],tgt[2]);

	return tgt;
}

vector<int> calibration::read_raw(int devNum)
{
	vector<int> tgt(3);
	
	if(devNum==1)
		Acc1.data_raw(tgt[0],tgt[1],tgt[2]);
	else if(devNum==2)
		Acc2.data_raw(tgt[0],tgt[1],tgt[2]);
	else if(devNum==3)
		Acc3.data_raw(tgt[0],tgt[1],tgt[2]);
	else if(devNum==4)
		Acc4.data_raw(tgt[0],tgt[1],tgt[2]);
	
	return tgt;
}