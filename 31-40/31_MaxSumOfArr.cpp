#include <iostream>

using namespace std;

int MaxSumOfArr(int arr[], int size)
{
	if (arr == NULL || size <= 0)
	{
		throw exception("Invalid Parameters");
	}
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (sum < 0)
		{
			sum = arr[i];
		}
		else
		{
			ans = max(ans, sum);
			sum += arr[i];
		}
	}
	return ans;
}

void Test_31_MaxSumOfArr()
{
	int arr[] = 
	{
		1, -2, 3, 10, -4, 7, 2, -5
	};
	try
	{
		cout << MaxSumOfArr(arr, sizeof(arr) / sizeof(int)) << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}