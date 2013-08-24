#include <iostream>

#include "3_FindNumberInYoungMatrix.h"

using namespace std;

bool FindNumberInYoungMatrix(int *matrix, int row, int col, int num, int &ansRow, int &ansCol)
{
	ansRow = -1;
	ansCol = -1;
	if (matrix == NULL || row < 0 || col < 0)
	{
		return false;
	}
	// 从右上角开始查找
	int x = 0;
	int y = col - 1;
	while (x < row && y >= 0)
	{
		int tmpNum = matrix[x * col + y];
		if (tmpNum == num)
		{
			ansRow = x;
			ansCol = y;
			return true;
		}
		else if (tmpNum > num)
		{
			--y;
		}
		else
		{
			++x;
		}
	}
	return false;
}
void Test_3_FindNumberInYoungMatrix()
{
	int matrix[] =
	{
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};

	int testArr[] = 
	{
		-100, -10, -5, -1,
		1, 2, 8, 9,
		3, 5,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15,
		100, 1000, 10000, 100000
	};

	int ansRow = -1;
	int ansCol = -1;
	int testCaseNum = sizeof(testArr) / sizeof(int);
	for (int i = 0; i < testCaseNum; ++i)
	{
		int bFound = FindNumberInYoungMatrix(matrix, 4, 4, testArr[i], ansRow, ansCol);
		if (bFound)
		{
			cout << "Number " << testArr[i] << " is in row " << (ansRow + 1) << " col " << (ansCol + 1) << endl;
		}
		else
		{
			cout << "Number " << testArr[i] << " is not found!" << endl;
		}
	}
}
