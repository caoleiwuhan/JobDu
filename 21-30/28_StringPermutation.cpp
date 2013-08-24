#include <iostream>
#include <string>
#include <algorithm>

#include "28_StringPermutation.h"

using namespace std;

// ÓÐÖØ¸´
void StringPermutationDFS(string str, int step)
{
	if (step >= str.length())
	{
		cout << str << endl;
		return;
	}
	for (int i = step; i < str.length(); ++i)
	{
		char ch = str[step];
		bool bSwap = true;
		for (int j = step; j < i; ++j)
		{
			if (str[j] == str[i])
			{
				bSwap = false;
				break;
			}
		}
		if (bSwap)
		{
			str[step] = str[i];
			str[i] = ch;
		StringPermutationDFS(str, step + 1);
			ch = str[step];
			str[step] = str[i];
			str[i] = ch;
		}
	}
}

void StringPermutation(string str)
{
	if (str.length() == 0)
	{
		return;
	}
	StringPermutationDFS(str, 0);
}


void StringCombination(string str)
{
	if (str.length() == NULL)
	{
		return;
	}
	sort(str.begin(), str.end());
	bool used[1024] = {false};
	string ans = "";
	set<string> strSet;
	for (int i = 1; i <= str.length(); ++i)
	{
		//StringCombinationDFS(str, used, ans, i);
		StringCombinationDFS(str, used, ans, i, strSet);
	}
}

void StringCombinationDFS(string str, bool used[], string ans, int len)
{
	if (ans.length() >= len)
	{
		cout << ans << endl;
		return;
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (!used[i])
		{
			used[i] = true;
			ans += str[i];
			StringCombinationDFS(str, used, ans, len);
			ans.erase(ans.end() - 1);
			used[i] = false;
		}
	}
}

void StringCombinationDFS(string str, bool used[], string ans, int len, set<string> &strSet)
{
	if (ans.length() >= len)
	{
		string tmp = ans;
		sort(tmp.begin(), tmp.end());
		if (strSet.find(tmp) == strSet.end())
		{
			cout << tmp << endl;
			strSet.insert(tmp);
		}
		return;
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (!used[i])
		{
			used[i] = true;
			ans += str[i];
			StringCombinationDFS(str, used, ans, len, strSet);
			ans.erase(ans.end() - 1);
			used[i] = false;
		}
	}
}

void Test_28_StringPermutation()
{
	//StringPermutation("aabb");
	StringCombination("abc");
}