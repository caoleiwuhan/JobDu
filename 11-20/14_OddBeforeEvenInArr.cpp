#include <iostream>

using namespace std;


void OddBeforEvenInArr(int arr[], int size)
{
	if (arr == NULL || size <= 0)
	{
		throw std::exception("Invalid Input");
	}
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		while ((left < right) && (arr[left] & 1))
		{
			++left;
		}
		while ((left < right) && (!(arr[right] & 1)))
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
}

void Test_14_OddBeforeEvenInArr()
{
	/* 测试用例：
			全是奇数
			全是偶数
			奇数、偶数相间
			随机
	*/
	int arr[] =
	{
		1,2,2,1,1,2,2
	};

	OddBeforEvenInArr(arr, sizeof(arr) / sizeof(int));

}