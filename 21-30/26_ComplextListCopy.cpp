#include <iostream>

#include "26_ComplextListCopy.h"

using namespace std;


ComplextListNode *ComplextListCopy(ComplextListNode *pHead)
{
	ComplextListNodeDup(pHead);
	ComplextListNodeSetSibling(pHead);
	ComplextListNode *pAns = ComplextListNodeDivide(pHead);
	return pAns;
}

void ComplextListNodeDup(ComplextListNode *pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	ComplextListNode *p = pHead;
	while (p != NULL)
	{
		ComplextListNode *pTmp = new ComplextListNode(p->key);
		pTmp->next = p->next;
		p->next = pTmp;
		p = p->next->next;
	}
}

void ComplextListNodeSetSibling(ComplextListNode *pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	ComplextListNode *p = pHead;
	while (p != NULL)
	{
		ComplextListNode *pNext = p->next;
		pNext->sibling = p->sibling->next;
	}
}

ComplextListNode * ComplextListNodeDivide(ComplextListNode *pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	
	ComplextListNode *pOld = pHead;
	ComplextListNode *pAns = pOld->next;
	if (pAns == NULL)
	{
		throw std::exception("Invalid parameter");
	}
	ComplextListNode *pNew = pAns->next;

	while (pNew != NULL)
	{
		pOld->next = pNew->next;
		pOld = pOld->next;
		if (pOld == NULL)
		{
			throw std::exception("Invalid parameter");
		}		
		pNew->next = pOld->next;
		pNew = pNew->next;
		if (pNew == NULL)
		{
			throw std::exception("Invalid parameter");
		}
	}
	return pAns;
}

void Test_26_ComplexListCopy()
{

}