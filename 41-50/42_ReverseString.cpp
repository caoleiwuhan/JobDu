#include <iostream>
#include <string>

#include "42_ReverseString.h"

using namespace std;


void ReverseString(char *pChar)
{
	if (pChar == NULL)
		return;
	char *pStart = pChar;
	char *pEnd = pStart;
	char *pPrev = pStart;
	while (*pEnd)
	{
		pPrev = pEnd;
		++pEnd;
	}
	
	char *pCur1 = pStart;
	char *pCur2 = pStart;
	while (pCur2 != pEnd)
	{
		if (*pCur2 != ' ')
		{
			pCur2++;
		}
		else
		{
			if (pCur1 != pCur2)
			{
				ReverseStringWithPos(pCur1, pCur2 - 1);			
			}
			pCur2++;
			pCur1 = pCur2;
		}
	}
	if (pCur1 != pCur2)
	{
		ReverseStringWithPos(pCur1, pCur2 - 1);			
	}

	ReverseStringWithPos(pStart, pPrev);
}

void ReverseStringWithPos(char *pStart, char *pEnd)
{
	while (pStart < pEnd)
	{
		char ch = *pStart;
		*pStart = *pEnd;
		*pEnd = ch;
		++pStart;
		--pEnd;
	}
}

void Test_42_ReverseString()
{
	char ch1[] = "I am a student.";
	ReverseString(ch1);
	cout << ch1 << endl;

	char ch2[] = "   ";
	ReverseString(ch2);
	cout << ch2 << endl;

	char ch3[] = "  H   el lo wor   ld  ";
	ReverseString(ch3);
	cout << ch3 << endl;

	char ch4[] = "  Hello world  !";
	ReverseString(ch4);
	cout << ch4 << endl;
}