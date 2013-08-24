#include <iostream>

#include "20_PrintMatrixClockOrder.h"

using namespace std;

void PrintMatrixClockOrder(int matrix[], int row, int col)
{
	if (matrix == NULL || row <= 0 || col <= 0)
	{
		throw std::exception("Invalid Parameter");
	}
	int x = 0;
	int y = 0;

	int up = 0;
	int down = row - 1;
	int left = 0;
	int right = col - 1;
	while (left <= right && up <= down)
	{
		for (int i = left; i <= right; ++i)
		{
			cout << matrix[up * col + i] << ' ';
		}
		++up;

		if (up > down)
			break;

		for (int i = up; i <= down; ++i)
		{
			cout << matrix[i * col + right] << ' ';
		}
		--right;

		if (left > right)
			break;

		for (int i = right; i >= left; --i)
		{
			cout << matrix[down * col + i] << ' ';
		}
		--down;
		if (up > down)
			break;

		for (int i = down; i >= up; --i)
		{
			cout << matrix[i * col + left] << ' ';
		}
		++left;
	}
}
void Test_20_PrintMatrixclockOrder()
{
	int matrix[] = 
	{
		1	
	};

	PrintMatrixClockOrder(matrix, 1, 1);
}