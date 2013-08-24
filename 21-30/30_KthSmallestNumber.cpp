#include <iostream>
#include "30_KthSmallestNumber.h"

using namespace std;

// 结果就放在数组中？还是放到一个新的数组中？
void KthSmallestNumber(int arr[], int size, int k)
{
	if (arr == NULL || k <= 0 || size <= k)
	{
		throw exception("Invalid Parameters");
	}
	int left = 0;
	int right = size - 1;
	while (k != 0)
	{
		int index = -1;
		try
		{
			index = KthSmallestPartition(arr, left, right);
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
			exit(-1);
		}
		int cur = (index - left) + 1;
		if (cur == k)
		{			
			break;
		}
		else if (cur < k)
		{
			left = index + 1;
			k -= cur;
		}
		else
		{
			right = index - 1;
		}
	}
}

int KthSmallestPartition(int arr[], int start, int to)
{
	if (arr == NULL || start < 0 || to < start)
	{
		throw exception("Invalid Parameters");
	}
	int num = arr[start];
	int left = start + 1;
	int right = to;
	while (left <= right)
	{
		while (arr[left] < num)
		{
			++left;
		}
		while (arr[right] >= num)
		{
			--right;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	arr[start] = arr[right];
	arr[right] = num;
	return right;
}

void Test_30_KthSmallestNumber()
{
	
	for (int i = -1; i <= 10; ++i)
	{
		int arr[] = 
		{
			4, 5, 1, 6, 2, 7, 3, 8
		};
		try
		{
			KthSmallestNumber(arr, 8, i);
			for (int j = 0; j < i; ++j)
			{
				cout << arr[j] << ' ';
			}
			cout << endl;
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
		}		
	}
	
}