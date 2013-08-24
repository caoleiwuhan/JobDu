#include <iostream>
#include <vector>

#include "36_CountOfReversePair.h"

using namespace std;

int CountOfReversePair(int arr[], int size)
{
	if (arr == NULL || size <= 1)
	{
		return 0;
	}
	return CountOfPairHelp(arr, 0, size - 1);
}

int CountOfPairHelp(int arr[], int from, int to)
{
	if (from >= to)
	{
		return 0;
	}
	int mid = from + ((to - from) >> 1);
	int ans = 0;
	ans += CountOfPairHelp(arr, from, mid);
	ans += CountOfPairHelp(arr, mid + 1, to);
	int left = from;
	int right = mid + 1;
	// 需要用到辅助数组，用来暂存归并好的数。
	vector<int> vec;
	while (left <= mid || right <= to)
	{
		// 左边已经没有
		if (left > mid)
		{
			vec.push_back(arr[right++]);
		}
		else if (right > to)
		{// 右边已经没有
			vec.push_back(arr[left++]);
			// 右边的个数
			//ans += (to - mid);
		}
		else
		{// 两边都有
			if (arr[left] <= arr[right])
			{
				vec.push_back(arr[left++]);
			}
			else 
			{
				vec.push_back(arr[right++]);
				// 左边剩余的个数
				ans += (mid - left + 1);
			}
		}
	}
	// 将vec中的数拷贝到arr中
	for (int i = 0; i < vec.size(); ++i)
	{
		arr[from + i] = vec[i];
	}
	return ans;
}

void Test_36_CountOfReversePair()
{
	int arr[] = 
	{
		7, 5, 6, 4
	};
	cout << CountOfReversePair(arr, sizeof(arr) / sizeof(int)) << endl;
}