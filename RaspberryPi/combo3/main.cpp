/*main.cpp*/
#include "acc.h"

using namespace std;

int main()
{

	double x,y,z;

	Acc acc1(1);
	Acc acc2(2);
	Acc acc3(3);
	Acc acc4(4);
	for(int i = 0; i<100; i++)
	{
		cout << "\t------------------\t" << endl;
		acc1.data(x,y,z);
		cout << "Acc 1 Data:" << endl;
		cout << "\tX: " << x << "\tY: " << y << "\tZ: " << z << "\n" << endl;
		
		acc2.data(x,y,z);
		cout << "Acc 2 Data:" << endl;
		cout << "\tX: " << x << "\tY: " << y << "\tZ: " << z << "\n" << endl;
		
		acc3.data(x,y,z);
		cout << "Acc 3 Data:" << endl;
		cout << "\tX: " << x << "\tY: " << y << "\tZ: " << z << "\n" << endl;
		
		acc4.data(x,y,z);
		cout << "Acc 4 Data:" << endl;
		cout << "\tX: " << x << "\tY: " << y << "\tZ: " << z << "\n\n" << endl;
		delay(1000);
	}
	return 1;
}