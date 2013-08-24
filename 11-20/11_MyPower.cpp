#include <iostream>

#include "11_MyPower.h"

using namespace std;

bool IsEqualZero(double num)
{
	return (fabs(num) <= EPSILON);
}

double MyPower(double base, int exp)
{
	if (IsEqualZero(base) && (exp == 0))
	{
		return 0;
	}
	if (IsEqualZero(base))
	{
		return 0;
	}

	if (exp == 0)
	{
		return 1;
	}
	if (exp == 1)
	{
		return base;
	}
	bool bNeg = false;
	if (exp < 0)
	{
		bNeg = true;
		exp = -exp;
	}
	double ans = MyPowerHelpRecursion(base, exp);
	// 如果是负数同时指数为奇数
	if (bNeg)
	{
		ans = 1.0 / ans;
	}
	return ans;
}

double MyPowerHelpRecursion(double base, int exp)
{
	if (exp == 0)
	{
		return 1;
	}
	if (exp == 1)
	{
		return base;
	}
	if (exp & 1)
	{
		return MyPowerHelpRecursion(base, exp - 1) * base;
	}
	else
	{
		double tmp = MyPowerHelpRecursion(base, exp >> 1);
		return tmp * tmp;
	}
}

double MyPowerHelpIterator(double base, int exp)
{
	double ans = 0;
	int tmp = base;
	while (exp)
	{
		if (exp & 1)
		{
			ans += tmp;
		}
		tmp *= base;
		exp >>= 1;
	}
	return ans;
}

void Test_11_MyPower()
{
}