#ifndef __5_PRING_LIST_REVERSE__
#define __5_PRING_LIST_REVERSE__

#include <iostream>

using namespace std;

#ifndef _LISTNODE_
#define _LISTNODE_

struct ListNode
{
	int key;
	ListNode *next;

	ListNode() : key(0), next(NULL){}
	ListNode(int _key) : key(_key), next(NULL) {}
	ListNode(int _key, ListNode *_next) : key(_key), next(_next) {}
};
#endif

void PrintListReverse(const ListNode *p);

// ΩË÷˙’ª
void PrintListReverseWithStack(const ListNode *p);
void Test_5_PrintListReverse();

void PrintList(ListNode *pHead);

#endif