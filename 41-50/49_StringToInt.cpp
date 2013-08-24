#include <iostream>
#include <string>

using namespace std;

int StringToInt(string str)
{
	if (str.empty())
	{
		throw exception("Invalid Parameter");
	}
	int len = str.length();
	if (len == 0)
	{
		return 0;
	}
	if (len > 10)
	{
		throw std::exception("Too Long");
	}
	int ans = 0;
	int pos = 0;
	bool bNeg = false;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
		{
			bNeg = true;
		}
		++pos;
	}
	// 除了0以外，不能以0开头：0123（不合法） +0 -0	+0123
	if ((str[pos] == '0' && (pos + 1 < len)) ||
		(pos == 1 && (str[pos] == '0')))
	{
		throw std::exception("Invalid Parameter");
	}
	while (pos < len)
	{
		if (!isdigit(str[pos]))
		{
			throw std::exception("Invalid Parameter");
		}
		ans = ans * 10 + (str[pos] - '0');
		++pos;
	}
	if (bNeg)
	{
		ans = -ans;
	}
	return ans;
}


void Test_49_StringToInt()
{
	try
	{
		cout << StringToInt("+0") << endl; // 不合法
		
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{		
		cout << StringToInt("-0") << endl; // 不合法

	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << StringToInt("12343214321432432") << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << StringToInt("-12a3") << endl;
		cout << StringToInt("1253b3") << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << StringToInt("1253b3") << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}