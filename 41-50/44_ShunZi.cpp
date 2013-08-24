#include <iostream>
#include <algorithm>

#include "44_ShunZi.h"

using namespace std;

bool IsShunZi(int arr[], int size)
{
	if (arr == NULL || size <= 0 || size > 5)
	{
		return false;
	}
	sort(arr, arr + size);
	
	int range = 0;
	int i = 1;
	for (; i < size; ++i)
	{
		if (arr[i] >= 14)
		{
			break;
		}
		if (arr[i] == arr[i - 1])
			return false;

		range += (arr[i] - arr[i-1] - 1);
	}
	int remain = size - i;
	if (remain >= range)
	{
		return true;
	}
	return false;
}

void Test_44_IsShunZi()
{
}