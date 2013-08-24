#include <iostream>

#include "13_DeleteListNode.h"

using namespace std;


void DeleteListNode(ListNode *pHead, ListNode *pNode)
{
	if (pHead == NULL || pNode == NULL)
	{
		throw std::exception("Invalid Input");
	}
	// 如果是尾部节点呢？假设pNode不会是尾部节点
	if (pNode->next == NULL)
	{
		throw std::exception("delete node is the tail node");
	}
	ListNode *pDel = pNode->next;
	pNode->key = pDel->key;
	pNode->next = pDel->next;
	// 因为不是new出来的，所以无法使用delete清除堆内存。调用函数直接弹出栈就OK了
	//delete pDel;
}
void Test_13_DeleteListNode()
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

	DeleteListNode(&n1, &n3);
	DeleteListNode(&n1, &n1);

}