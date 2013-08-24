#include <iostream>
#include "47_AddWithoutOpr.h"

using namespace std;

int AddWithoutOpr(int a, int b)
{
	int c = a & b;
	int d = a ^ b;
	while (c != 0)
	{
		c <<= 1;
		int tmp = c;
		c &= d;
		d ^= tmp;
	}
	return d;
}


void Test_47_AddWithoutOpr()
{
	cout << AddWithoutOpr(1, 1) << endl;

	for (int i = 0; i <= 4; ++i)
		for (int j = 0; j <= 4; ++j)
		{
			cout << i << " + " << j << " = " << AddWithoutOpr(i, j) << endl;
		}
}