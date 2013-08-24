#include <iostream>

using namespace std;

struct ComplextListNode
{
	int key;
	ComplextListNode *next;
	ComplextListNode *sibling;

	ComplextListNode(int _key) : key(_key), next(NULL), sibling(NULL) {}
};


ComplextListNode *ComplextListCopy(ComplextListNode *pHead);

void ComplextListNodeDup(ComplextListNode *pHead);

void ComplextListNodeSetSibling(ComplextListNode *pHead);

ComplextListNode * ComplextListNodeDivide(ComplextListNode *pHead);

void Test_26_ComplexListCopy();