#include <iostream>
#include <cassert>

#include "1_OperatorFunction.h"

using namespace std;

CMyString::CMyString(char *pData)
{
	if (pData == NULL)
	{
		m_pData = NULL;
		return;
	}
	int len = strlen(pData);
	m_pData = new char[len + 1];
	if (m_pData == NULL)
	{
		cerr << "Allocate Memory Failed in Constructor!" << endl;
		exit(-1);
	}
	strcpy(m_pData, pData);
}

CMyString::CMyString(const CMyString & str)
{
	if (str.m_pData == NULL)
	{
		this->m_pData = NULL;
		return;
	}
	m_pData = new char[strlen(str.m_pData) + 1];
	if (m_pData == NULL)
	{
		cerr << "Allocate Memory Failed in Copy Constructor!" << endl;
		exit(-1);
	}
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	if (m_pData != NULL)
	{
		delete[] m_pData;
		m_pData = NULL;
	}
}

CMyString & CMyString::operator=(const CMyString & str)
{
	if (str.m_pData == NULL)
	{
		m_pData = NULL;
	}
	else
	{
		if (this != &str)
		{
			char *pTmp = new char[strlen(str.m_pData) + 1];
			if (pTmp == NULL)
			{
				cerr << "Allocate Memory Failed in Copy Assigned!" << endl;
				exit(-1);
			}
			strcpy(pTmp, str.m_pData);
			delete[] m_pData;
			m_pData = pTmp;
		}
	}
	return *this;
}
/*
// 书上提供的实现：
CMyString & CMyString::operator=(const CMyString & str)
{
	if (this != &str)
	{
		CMyString strTmp(str);
		// 与原来的交换
		char *pTmp = strTmp.m_pData;
		strTmp.m_pData = this->m_pData;
		m_pData = pTmp;
	}
	return *this;
}
*/

void Test_1_OperatorFunction()
{
	// 1:测试构造函数
	char *pChar = "Hello World";
	CMyString str1(pChar);
	CMyString str2;

	// 2:测试拷贝构造
	CMyString str3(str1);
	CMyString str4(str2);

	// 3:测试拷贝赋值
	char *pChar2 = "MicroSoft";
	CMyString str5(pChar2);
	CMyString str6(pChar2);
	str5 = str6;
	str6 = str1;
	str6 = str6;
	str6 = str2;
}
