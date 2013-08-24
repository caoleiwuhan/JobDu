#include <iostream>
#include <cassert>

#include "10_OneNumber.h"

using namespace std;


int OneNumber(int num)
{
	if (num == 0)
		return 0;
	int ans = 1;
	while (num & (num - 1))
	{
		++ans;
		num &= (num - 1);
	}
	return ans;
}

int OneNumber2(int num)
{
	int ans = 0;
	while (num)
	{
		++ans;
		num &= (num - 1);
	}
	return ans;
}

void Test_10_OneNumber()
{
	int num = 9;
	cout << OneNumber(9) << endl;
	assert(OneNumber(9) == 2);

	num = 8;
	cout << OneNumber(8) << endl;
	assert(OneNumber(8) == 1);

	num = 7;
	cout << OneNumber(7) << endl;
	assert(OneNumber(7) == 3);

	cout << OneNumber(-1) << endl;
	cout << OneNumber(0x80000000) << endl;
	
}