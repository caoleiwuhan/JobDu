#include <iostream>

#include "17_MergeTwoSortedList.h"

using namespace std;


ListNode *MergeTwoSortedList(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
	{
		return p2;
	}
	if (p2 == NULL)
	{
		return p1;
	}
	ListNode *pAns = NULL;
	ListNode *pCur = NULL;
	if (p1->key < p2->key)
	{
		pAns = p1;
		p1 = p1->next;		
	}
	else
	{
		pAns = p2;
		p2 = p2->next;		
	}
	pCur = pAns;

	while (p1 || p2)
	{
		if (p1 == NULL)
		{
			pCur->next = p2;
			p2 = p2->next;
		}
		else if (p2 == NULL)
		{
			pCur->next = p1;
			p1 = p1->next;
		}
		else
		{
			if (p1->key < p2->key)
			{
				pCur->next = p1;
				p1 = p1->next;
			}
			else
			{
				pCur->next = p2;
				p2 = p2->next;
			}
		}
		pCur = pCur->next;
	}
	return pAns;
}
void Test_17_MergeTwoSortedList()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);

	/*
		1：有为空的
		2：list1都小于list2
		3：交叉
	*/
	ListNode *p1 = &n1;
	n1.next = &n4;
	n4.next = &n5;

	ListNode *p2 = &n2;
	n2.next = &n3;
	n3.next = &n6;

	//ListNode *pAns = MergeTwoSortedList(p2, p1);
	ListNode *pAns = MergeTwoSortedListRecursion(p2, p1);
	PrintList(pAns);
}

ListNode *MergeTwoSortedListRecursion(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
	{
		return p2;
	}
	if (p2 == NULL)
	{
		return p1;
	}
	ListNode *pAns = NULL;
	if (p1->key < p2->key)
	{
		pAns = p1;
		p1 = p1->next;
	}
	else
	{
		pAns = p2;
		p2 = p2->next;
	}
	pAns->next = MergeTwoSortedListRecursion(p1, p2);
	return pAns;
}