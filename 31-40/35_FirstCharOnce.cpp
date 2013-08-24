#include <iostream>

#include "35_FirstCharOnce.h"

using namespace std;


char FirstCharOnce(string str)
{
	int len = str.length();
	if (len == 0)
	{
		throw exception("Invalid Parameter");
	}
	char hash[256]  = { 0 };
	for (int i = 0; i < len; ++i)
	{
		hash[str[i]]++;
	}
	for (int i = 0; i < len; ++i)
	{
		if (hash[str[i]] == 1)
		{
			return str[i];
		}
	}
	return '\0';
}
void Test_35_FirstCharOnce()
{
	try
	{
		cout << FirstCharOnce("abaccdeff") << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}