#include <iostream>
#include "24_IsPostOrderOfBinaryTree.h"

using namespace std;

bool IsPostOrderOfBinaryTree(int arr[], int size)
{
	if (arr == NULL || size <= 0)
	{
		return false;
	}
	return IsPostOrderOfBinaryTreeHelp(arr, 0, size - 1);
}


bool IsPostOrderOfBinaryTreeHelp(int arr[], int start, int end)
{
	if (start >= end)
	{
		return true;
	}
	int pivot = arr[end];
	int i = start;
	for (; i <= end; ++i)
	{
		if (arr[i] == pivot)
		{
			return false;
		}
		if (arr[i] > pivot)
		{
			break;
		}
	}
	// 在i后面的都要大于pivot
	for (int j = i; j <= end - 1; ++j)
	{
		if (arr[j] <= pivot)
		{
			return false;
		}
	}
	if (IsPostOrderOfBinaryTreeHelp(arr, start, i - 1) && IsPostOrderOfBinaryTreeHelp(arr, i, end - 1))
	{
		return true;
	}
	return false;
}

void Test_24_IsPostOrderOfBinary()
{
	int arr[] = 
	{
		7, 4, 6, 5
	};
	cout << IsPostOrderOfBinaryTree(arr, sizeof(arr) / sizeof(int)) << endl;
}