#ifndef __1_OPERATER_FUNCTION__
#define __1_OPERATER_FUNCTION__

#include <iostream>

using namespace std;

/*
	为以下结构定义赋值运算符
*/

/*
 * 功能：自定义字符串结构，包括构造函数、拷贝构造函数、赋值构造函数、析构函数
 * 
 */
  
struct CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString & str);
	// 为了支持str[i] = 
	/*
	 * 函数名		： = 
	 * 作者		： caolei
	 * 日期		： 2013-08-15
	 * 功能		： 完成自定义字符串的拷贝赋值功能
	 * 输入参数
			str：待拷贝字符串
	 * 返回值		： 拷贝完成的字符串的引用，为了连续赋值，例如str1 = str2 = str3;
	 */
	CMyString & operator = (const CMyString & str);
	~CMyString();

private:
	/*
	 * 用来存储字符的指针
	*/
	char * m_pData;
};

void Test_1_OperatorFunction();

#endif 