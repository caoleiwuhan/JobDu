#ifndef __13_DELETE_LISTNODE__
#define __13_DELETE_LISTNODE__

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

void DeleteListNode(ListNode *pHead, ListNode *pNode);

void Test_13_DeleteListNode();





#endif