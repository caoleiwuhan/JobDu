#include <iostream>

using namespace std;

void FindNumberOnce(int arr[], int size, int &num1, int &num2)
{
	if (arr == NULL || size <= 0)
	{
		throw std::exception("Invalid Parameter 1");
	}
	int i = 0;
	for (; i < 32; ++i)
	{
		unsigned mask = (1 << i);
		int tot = 0;
		for (int j = 0; j < size; ++j)
		{
			if (arr[j] & mask)
			{
				++tot;
			}
		}
		if (tot & 1)
		{
			break;
		}
	}
	if (i >= 32)
	{
		throw std::exception("Invalid Parameter 2");
	}
	num1 = 0;
	num2 = 0;
	unsigned mask = (1 << i);
	for (int j = 0; j < size; ++j)
	{
		if (arr[j] & mask)
		{
			num1 ^= arr[j];
		}
		else
		{
			num2 ^= arr[j];
		}
	}
}


void Test_40_FindNumberOnce()
{
	int arr[] = 
	{
		2, 4, 3, 6, 3, 2, 5, 5, 4, 6
	};
	int num1 = 0;
	int num2 = 0;
	try
	{
		FindNumberOnce(arr, sizeof(arr) / sizeof(int), num1, num2);
		cout << num1 << endl;
		cout << num2 << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}