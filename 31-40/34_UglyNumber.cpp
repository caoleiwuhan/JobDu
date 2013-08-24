#include <iostream>

#include "34_UglyNumber.h"
using namespace std;

int UglyNumber(int N)
{
	if (N <= 0)
	{
		return 0;
	}
	int *f = new int[N + 1];
	//int f[1501] = {0};
	int index[3] = {0, 0, 0};
	int weight[3] = {2, 3, 5};
	f[0] = 1;	
	int cur = 1;
	while (cur <= N)
	{
		int i = MinNumberOfThree(f[index[0]] * 2, f[index[1]] * 3, f[index[2]] * 5);
		int num = f[index[i]] * weight[i];
		index[i]++;
		for (int j = 0; j < 3; ++j)
		{
			if (j != i)
			{
				while (f[index[j]] * weight[j] <= num)
				{
					index[j]++;
				}
			}
		}
		f[cur++] = num;
	}
	int ans = f[N];
	delete []f;
	return ans;
}

int MinNumberOfThree(int num1, int num2, int num3)
{
	if (num1 <= num2 && num1 <= num3)
	{
		return 0;
	}
	if (num2 <= num1 && num2 <= num3)
	{
		return 1;
	}
	return 2;
}

void Test_34_UglyNumber()
{
	cout << UglyNumber(1500) << endl;
}