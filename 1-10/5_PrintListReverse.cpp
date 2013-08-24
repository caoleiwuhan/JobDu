#include <iostream>
#include <stack>
#include "5_PrintListReverse.h"

using namespace std;


// µÝ¹éÊµÏÖ
void PrintListReverse(const ListNode *p)
{
	if (p != NULL)
	{
		PrintListReverse(p->next);
		cout << p->key << endl;
	}	
}

void PrintListReverseWithStack(const ListNode *p)
{	
	stack<const ListNode *> s;
	while (p)
	{
		s.push(p);
		p = p->next;
	}
	while (!s.empty())
	{
		const ListNode *tmp = s.top();
		s.pop();
		cout << tmp->key << " ";
	}
	cout << endl;
}

void PrintList(ListNode *pHead)
{
	if (pHead == NULL)
		return;
	while (pHead)
	{
		cout << pHead->key << " ";
		pHead = pHead->next;
	}
	cout << endl;
}

void Test_5_PrintListReverse()
{
	ListNode l5(5);
	ListNode l4(4, &l5);
	ListNode l3(3, &l4);
	ListNode l2(2, &l3);
	ListNode l1(1, &l2);
	
	//PrintListReverse(&l1);
	PrintListReverseWithStack(&l1);
}
