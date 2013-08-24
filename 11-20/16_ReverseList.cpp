#include <iostream>

#include "16_ReverseList.h"

using namespace std;


void ReverseListRecursion(ListNode *&pHead, ListNode *&tail)
{
	if (pHead->next == NULL)
	{		
		tail = pHead;
	}
	else
	{
		ListNode *tmpHead = pHead->next;
		ListNode *tmpTail = NULL;
		ReverseListRecursion(tmpHead, tmpTail);
		tmpTail->next = pHead;		
		tail = pHead;
		pHead = tmpHead;
	}
}
void Test_16_ReverseList()
{
	ListNode n1(1);
	//ListNode n2(2);
	//ListNode n3(3);
	//ListNode n4(4);
	//ListNode n5(5);

	//n1.next = &n2;
	//n2.next = &n3;
	//n3.next = &n4;
	//n4.next = &n5;

	PrintList(&n1);
	
	ListNode *pHead = ReverseList(&n1);

	PrintList(pHead);
}

ListNode *ReverseList(ListNode *pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	//ListNode * pTail = NULL;
	//ReverseListRecursion(pHead, pTail);
	//pTail->next = NULL;
	
	//return pHead;
	return ReverseListIterator(pHead);
}

ListNode * ReverseListIterator(ListNode *pHead)
{
	ListNode *pCur = pHead;
	ListNode *pTo = pHead->next;
	pCur->next = NULL;
	while (pTo != NULL)
	{
		ListNode *pTmp = pTo->next;
		pTo->next = pCur;
		pCur = pTo;
		pTo = pTmp;
	}
	return pCur;
}