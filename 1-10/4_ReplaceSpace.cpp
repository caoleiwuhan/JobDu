#include <iostream>
#include <cassert>

#include "4_ReplaceSpace.h"

using namespace std;



void ReplaceSpace(char *str)
{
	if (str == NULL)
		return;

	// 1. 统计字符长的长度和空格的个数，计算统计后的总长度
	int len = strlen(str);
	int spaceNum = 0;
	char *p = str;
	while (*p)
	{
		if (*p++ == ' ')
		{
			++spaceNum;
		}
	}
	int ansLen = len + (spaceNum << 1);
	// 2.从后往前替换
	char *pAns = str + ansLen;
	*pAns-- = '\0';
	p = str + len - 1;
	while (*p)
	{
		if (*p != ' ')
		{
			*pAns-- = *p--;
		}
		else
		{
			*pAns-- = '0';
			*pAns-- = '2';
			*pAns-- = '%';
			--p;
		}
	}
}

void Test_4_ReplaceSpace()
{
	char str[1024] = " Hello  world  ";
	ReplaceSpace(str);
	cout << str << endl;
	assert(strcmp(str, "%20Hello%20%20world%20%20") == 0);
	
	strcpy(str, "Hello world");
	ReplaceSpace(str);
	cout << str << endl;
	assert(strcmp(str, "Hello%20world") == 0);

	strcpy(str, "  Hel lo wor  ld  ");
	ReplaceSpace(str);
	cout << str << endl;
	assert(strcmp(str, "%20%20Hel%20lo%20wor%20%20ld%20%20") == 0);


}