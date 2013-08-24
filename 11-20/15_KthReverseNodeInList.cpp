#include <iostream>
#include "15_KthReverseNodeInList.h"

using namespace std;

ListNode * KthReverseNodeInList(ListNode *pHead, int k)
{
	if (pHead == NULL || k <= 0)
	{
		throw std::exception("Invalid Parameter");
	}
	ListNode *pTmp = pHead;
	for (int i = 0; i < k; ++i)
	{
		if (!pTmp)
		{
			throw std::exception("The number of node is less than k");
		}
		pTmp = pTmp->next;
	}
	ListNode *pAns = pHead;
	while (pTmp)
	{
		pAns = pAns->next;
		pTmp = pTmp->next;
	}
	return pAns;
}
void Test_15_KthReverseNodeInList()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	try
	{
		ListNode *pAns = KthReverseNodeInList(NULL, 3);
		cout << "i : " << 3 << " is " << pAns->key << endl;
	}
	catch (std::exception &e)
	{
		cerr << e.what() << endl;
	}
	for (int i = -1; i < 8; ++i)
	{		
		try
		{
			ListNode *pAns = KthReverseNodeInList(&n1, i);
			cout << "i : " << i << " is " << pAns->key << endl;
		}
		catch (std::exception &e)
		{
			cerr << e.what() << endl;
		}
	}
}
