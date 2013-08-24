#include <iostream>

#include "37_FirstCommonListNode.h"

using namespace std;


ListNode *FirstCommonList(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL || p2 == NULL)
	{
		return NULL;
	}
	// 求其两个的长度
	int len1 = 1;
	int len2 = 1;
	ListNode *ptmp1 = p1;
	while (ptmp1->next != 0)
	{
		++len1;
		ptmp1 = ptmp1->next;
	}
	ListNode *ptmp2 = p2;
	while (ptmp2->next != 0)
	{
		++len2;
		ptmp2 = ptmp2->next;
	}
	// 最后一个节点不相同
	if (ptmp1 != ptmp2)
	{
		return NULL;
	}
	ptmp1 = p1;
	if (len1 > len2)
	{
		int dif = len1 - len2;
		while (dif)
		{
			ptmp1 = ptmp1->next;
			--dif;
		}
	}
	ptmp2 = p2;
	if (len2 > len1)
	{
		int dif = len2 - len1;
		while (dif)
		{
			ptmp2 = ptmp2->next;
			--dif;
		}
	}
	while (ptmp1 != ptmp2)
	{
		ptmp1 = ptmp1->next;
		ptmp2 = ptmp2->next;
	}
	return ptmp1;
}


void Test_37_FirstCommonList()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	ListNode n7(7);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n6;
	n6.next = &n7;
	n4.next = &n5;
	n5.next = &n6;

	// 正常情况
	cout << FirstCommonList(&n1, &n4)->key << endl;

	// 长度相等
	cout << FirstCommonList(&n2, &n4)->key << endl;

	// 
	cout << FirstCommonList(&n1, &n6)->key << endl;


}