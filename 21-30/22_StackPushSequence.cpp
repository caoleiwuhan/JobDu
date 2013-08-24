#include <iostream>
#include <stack>

#include "22_StackPushSequence.h"

using namespace std;

bool IsStackPushSequence(int arr1[], int arr2[], int size)
{
	if (arr1 == NULL && arr2 == NULL)
	{
		return true;
	}
	if (arr1 == NULL || arr2 == NULL || size <= 0)
	{
		return false;
	}
	stack<int> s;
	int index1 = 0;
	int index2 = 0;
	while (true)
	{
		while (index1 < size && arr1[index1] != arr2[index2])
		{
			s.push(arr1[index1++]);
		}
		if (index1 < size && arr1[index1] == arr2[index2])
		{
			++index1;
			++index2;
		}
		while (!s.empty() && s.top() == arr2[index2])
		{
			s.pop();
			++index2;
		}
		if (index2 >= size)
		{
			return true;
		}
		if (index1 >= size && index2 < size)
		{
			return false;
		}
	}
	return false;
}



void Test_22_IsStackPushSequence()
{
	int arr1[] = 
	{
		1, 2, 3, 4, 5
	};
	int arr2[] = 
	{
		4, 3, 5, 1, 2
	};

	cout << IsStackPushSequence(arr1, arr2, sizeof(arr1) / sizeof(int)) << endl;
}