#include <iostream>

#include "38_NumberCountInArr.h"

using namespace std;

int NumberCountInArr(int arr[], int size, int num)
{
	if (arr == NULL || size <= 0)
	{
		throw std::exception("Invalid Parameter");
	}
	int firstPos = -1;
	int lastPos = -1;
	try
	{
		firstPos = FirstIndexInArr(arr, size, num);
		lastPos = LastIndexInArr(arr, size, num);
		if (firstPos != -1 && lastPos != -1)
		{
			return (lastPos - firstPos + 1);
		}
		return 0;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

int FirstIndexInArr(int arr[], int size, int num)
{
	if (arr == NULL || size <= 0)
	{
		throw std::exception("Invalid Parameter");
	}
	int left = 0;
	int right = size - 1;
	while (left + 1 < right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] >= num)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	if (arr[left] == num)
	{
		return left;
	}
	if (arr[right] == num)
	{
		return right;
	}
	return -1;
}

int LastIndexInArr(int arr[], int size, int num)
{
	if (arr == NULL || size <= 0)
	{
		throw std::exception("Invalid Parameter");
	}
	int left = 0;
	int right = size - 1;
	while (left + 1 < right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] <= num)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	if (arr[right] == num)
	{
		return right;
	}
	if (arr[left] == num)
	{
		return left;
	}
	return -1;
}

void Test_38_NumberCountInArr()
{
	int arr[] = 
	{
		1, 2, 2, 3, 3, 3, 3, 4, 5
	};
	try
	{
		int count = NumberCountInArr(arr, sizeof(arr) / sizeof(int), 2);
		cout << count << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}