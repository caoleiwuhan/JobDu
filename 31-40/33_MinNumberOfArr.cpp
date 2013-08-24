#include <iostream>
#include <algorithm>

#include "33_MinNumberOfArr.h"

using namespace std;

string MinNumberOfArr(int arr[], int size)
{
	if (arr == NULL || size <= 0)
	{
		throw exception("Invalid Parameter");
	}
	sort(arr, arr + size, SortFunction);
	string ans = "";
	char buf[1024];
	for (int i = 0; i < size; ++i)
	{
		itoa(arr[i], buf, 10);
		ans += buf;
	}
	return ans;
}

bool SortFunction(int num1, int num2)
{
	char str1[32];
	char str2[32];
	itoa(num1, str1, 10);
	itoa(num2, str2, 10);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	strncpy(str1 + len1, str2, len2);
	strncpy(str2 + len2, str1, len1);
	if (strcmp(str1, str2) <= 0)
	{
		return true;
	}
	return false;
}

void Test_33_MinNumberOfArr()
{
	int arr[] = 
	{
		3, 32, 321
	};
	try
	{
		string ans = MinNumberOfArr(arr, sizeof(arr) / sizeof(int));
		cout << ans << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}