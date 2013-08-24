#include <iostream>
#include "29_MoreHalfOfArr.h"

using namespace std;

int MoreHalfOfArr(int arr[], int size)
{
	if (arr == NULL || size <= 0)
	{
		throw exception("Invalid Parameters");
	}
	// 如果与前面的相同，就想加，否则，相减
	int num = arr[0];
	int count = 1;
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] == num)
		{
			++count;
		}
		else
		{
			--count;
			if (count == 0)
			{
				num = arr[i];
				count = 1;
			}
		}
	}
	return num;
}

void Test_29_MoreHalfOfArr()
{
	try
	{
		int arr[] = 
		{
			1, 2, 3, 2, 2, 2, 5, 4, 2
		};
		cout << MoreHalfOfArr(arr, sizeof(arr) / sizeof(int)) << endl;
	}
	catch (exception &e)
	{
		e.what();
	}
}