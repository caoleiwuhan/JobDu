#include <iostream>

#include "43_TouZi.h"

using namespace std;

void TouZi(int N)
{
	if (N <= 0)
	{
		return;
	}
	int **f = new int*[2];
	f[0] = new int[6 * N + 1];
	f[1] = new int[6 * N + 1];

	if (f == NULL || f[0] == NULL || f[1] == NULL)
	{
		throw exception("Malloc memory Failed!");
	}
	memset(f[0], 0, sizeof(int) * (6 * N + 1));
	memset(f[1], 0, sizeof(int) * (6 * N + 1));

	f[0][1] = f[0][2] = f[0][3] = f[0][4] = f[0][5] = f[0][6] = 1;
	int flag = 0;
	for (int i = 2; i <= N; ++i)
	{
		int to = (i - 1) * 6;
		int start = i - 1;
		for (int j = to; j >= start; --j)
		{
			if (f[flag][j] != 0)
			{
				for (int k = 1; k <= 6; ++k)
				{
					f[1 - flag][j + k]++;
				}
			}
		}
		memset(f[flag], 0, sizeof(int) * (6 * N + 1));
		flag = 1 - flag;
	}
	double tot = pow(6.0, N);
	for (int i = N; i <= 6 * N; ++i)
	{		
		if (f[flag][i])
		{
			double p = f[flag][i] / tot;
			cout << "点数：" << i << " 出现的概率为： " << p << endl;
		}
	}

	delete[] f[0];
	delete[] f[1];
	delete[] f;
}

void Test_43_TouZi()
{
	for (int i = 1; i < 4; ++i)
	{
		cout << "-------------------------------------------" << endl;
		TouZi(i);
	}
}