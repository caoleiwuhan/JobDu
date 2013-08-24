#include <iostream>

#include "9_Fibonacci.h"

using namespace std;


/*
	f(1) = 1
	f(2) = 1
	f(3) = 2
	...
*/
int FibonacciRecersive(int n)
{
	if (n <= 0)
	{
		throw std::exception("Invalid Input");
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FibonacciRecersive(n - 1) + FibonacciRecersive(n - 2);
}

int FibonacciIterator(int n)
{
	if (n <= 0)
	{
		throw std::exception("Invalid Input");
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int n1 = 1;
	int n2 = 2;
	int n3 = -1;
	for (int i = 3; i <= n; ++i)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n2;
}

long long FibonacciIterator2(int n)
{
	if (n <= 0)
	{
		throw std::exception("Invalid Input");
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	long long n1 = 1;
	long long n2 = 2;
	long long n3 = -1;
	for (int i = 3; i <= n; ++i)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n2;
}

int FibonacciPower(int n)
{
	if (n <= 0)
	{
		throw std::exception("Invalid Input");
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	/*
		(f(n), f(n-1)) = (f(n-1), f(n-2))	[1 1]
											[1 0]
		(f(3), f(2)) = (f(1), f(2)) * A
		(f(4), f(3)) = (f(1), f(2)) * Pow(A, 2)
		(f(n), f(n-1)) = (f(1), f(2)) * Pow(A, n-2)
	*/
	int arr[4] = 
	{
		1, 1,
		1, 0
	};
	int ans[4];
	PowerHelp(arr, ans, n - 2);
	int res = ans[0] + ans[2];
	return res;
}

void PowerHelp(int arr[], int ans[], int n)
{
	if (n < 0)
	{
		ans[0] = ans[1] = ans[2] = ans[3] = 0;
		return;
	}
	if (n == 0)
	{
		ans[0] = ans[1] = ans[2] = ans[3] = 1;
		return;	
	}
	int tmp[4];
	if (n & 1)
	{ // 如果n为奇数
		PowerHelp(arr, tmp, n - 1);
		ans[0] = tmp[0] + tmp[1];
		ans[1] = tmp[0];
		ans[2] = tmp[2] + tmp[3];
		ans[3] = tmp[2];
	}
	else
	{
		PowerHelp(ans, tmp, n >> 1);
		ans[0] = tmp[0] * tmp[0] + tmp[1] * tmp[2];
		ans[1] = tmp[0] * tmp[1] + tmp[1] * tmp[2];
		ans[2] = tmp[2] * tmp[0] + tmp[3] * tmp[2];
		ans[3] = tmp[2] * tmp[1] + tmp[3] * tmp[2];
	}
}


void Test_9_Fibonacci()
{
}