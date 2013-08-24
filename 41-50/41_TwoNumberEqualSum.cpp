#include <iostream>
#include "41_TwoNumberEqualSum.h"

using namespace std;

bool TwoNumberEqualSum(int arr[], int size, int &num1, int &num2, int sum)
{
	if (arr == NULL || size <= 0)
	{
		throw std::exception("Invalid Parameter 1");
	}
	for (int i = 1; i < size; ++i)
	{
		if (arr[i-1] > arr[i])
		{
			throw std::exception("Invalid Parameter 2");
		}
	}
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int tmp = arr[left] + arr[right];
		if (tmp == sum)
		{
			num1 = arr[left];
			num2 = arr[right];
			return true;
		}
		else if (tmp > sum)
		{
			--right;
		}
		else
		{ 
			++left;
		}
	}
	return false;
}
void Test_41_TwoNumberEqualSum()
{	
	/*try
	{
		int arr[] = 
		{
			1, 2, 4, 7, 11, 15
		};
		int num1 = 0;
		int num2 = 0;
		bool bFound = TwoNumberEqualSum(arr, sizeof(arr) / sizeof(int), num1, num2, 15);
		if (bFound)
		{
			cout << num1 << " " << num2 << endl;
		}
		else
		{
			cout << "Not Found!" << endl;
		}
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}*/

	try
	{
		NumberEqualSum(15, 15);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

bool NumberEqualSum(int N, int sum)
{
	if (N <= 0)
	{
		throw std::exception("Invalid Parameter");
	}
	if (N == 1)
	{
		return false;
	}
	int tmp = 1 + 2;
	int left = 1;
	int right = 2;
	while (right <= N)
	{
		if (tmp == sum)
		{
			if (left < right)
			{
				PrintNumber(left, right);
			}
			tmp -= left;
			++left;
		}
		else if (tmp > sum)
		{
			tmp -= left;
			++left;
		}
		else
		{
			++right;
			tmp += right;
		}
	}
}

void PrintVec(int arr[], int size, int from, int to)
{
	if (arr == NULL || size <= 0 || to >= size || from < 0)
	{
		return;
	}
	for (int i = from; i <= to; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void PrintNumber(int from, int to)
{
	for (int i = from; i <= to; ++i)
	{
		cout << i << ' ';
	}
	cout << endl;
}