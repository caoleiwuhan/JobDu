#ifndef __3_FIND_NUMBER_IN_YOUNG_MATRIX__
#define __3_FIND_NUMBER_IN_YOUNG_MATRIX__


/*
 * 函数名	：FindNumberInYoungMatrix
 * 功能	：在杨氏矩阵中查找一个数，如果该数存在，返回true，同时返回row、col的引用
 * 作者	：
 * 时间	：
 * 输入值：
	@matrix	：矩阵
	@row	：矩阵的行数
	@col	：矩阵的列数
	@num	：待查找的数
	@ansRow	：所在的行（如果存在的话，否则返回-1）
	@ansCol	：所在的列（如果存在的话，否则返回-1）
 * 返回值：
	true	：待查找的数在矩阵中
	false	：待查找的数不在矩阵中
 */
bool FindNumberInYoungMatrix(int *matrix, int row, int col, int num, int &ansRow, int &ansCol);

void Test_3_FindNumberInYoungMatrix();






#endif __3_FIND_NUMBER_IN_YOUNG_MATRIX__