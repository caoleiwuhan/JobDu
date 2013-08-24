#include <iostream>

using namespace std;

int CountOfNumber(int N)
{
	// 需要解析出high、low、factor
	int count = 0;
	if (N <= 0)
	{
		return 0;
	}
	int high = 0;
	int low = 0;
	int factor = 1;
	int digit = 0;
	while (factor <= N)
	{
		low = N % factor;
		high = N / (factor * 10);
		digit = (N / factor) % 10;
		if (digit == 1)
		{
			count += (low + 1) + high * factor;
		}
		else if (digit == 0)
		{
			count += high * factor;
		}
		else
		{
			count += (high + 1) * factor;
		}
		factor *= 10;
	}
	return count;
}
void Test_32_CountOfNumber()
{	
	cout << CountOfNumber(10) << endl;
	cout << CountOfNumber(11) << endl;
	cout << CountOfNumber(18) << endl;

	cout << CountOfNumber(20) << endl;
	cout << CountOfNumber(21) << endl;
	cout << CountOfNumber(28) << endl;

	cout << CountOfNumber(30) << endl;
	cout << CountOfNumber(31) << endl;
	cout << CountOfNumber(38) << endl;

	cout << CountOfNumber(100) << endl;
	cout << CountOfNumber(101) << endl;
	cout << CountOfNumber(108) << endl;

	cout << CountOfNumber(110) << endl;
	cout << CountOfNumber(111) << endl;
	cout << CountOfNumber(118) << endl;

	cout << CountOfNumber(120) << endl;
	cout << CountOfNumber(121) << endl;
	cout << CountOfNumber(128) << endl;

	cout << CountOfNumber(130) << endl;
	cout << CountOfNumber(131) << endl;
	cout << CountOfNumber(138) << endl;

	cout << CountOfNumber(200) << endl;
	cout << CountOfNumber(201) << endl;
	cout << CountOfNumber(208) << endl;
	cout << CountOfNumber(210) << endl;
	cout << CountOfNumber(211) << endl;
	cout << CountOfNumber(218) << endl;
	cout << CountOfNumber(220) << endl;
	cout << CountOfNumber(221) << endl;
	cout << CountOfNumber(228) << endl;
	cout << CountOfNumber(21325) << endl;
}