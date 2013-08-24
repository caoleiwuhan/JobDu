#include <iostream>
#include "27_BinaryTreeToList.h"

using namespace std;

TreeNode *BinaryTreeToList(TreeNode *pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	TreeNode *pHead;
	TreeNode *pTail;
	TreeToListHelp(pRoot, pHead, pTail);
	return pHead;
}

void TreeToListHelp(TreeNode *pRoot, TreeNode *&pHead, TreeNode *&pTail)
{
	if (pRoot == NULL)
	{
		throw std::exception("Invalid Input");
	}
	if (pRoot->left == NULL && pRoot->right == NULL)
	{
		pHead = pRoot;
		pTail = pRoot;
		return;
	}
	TreeNode *pLeftHead = NULL;
	TreeNode *pLeftTail = NULL;
	TreeNode *pRightHead = NULL;
	TreeNode *pRightTail = NULL;
	if (pRoot->left != NULL)
	{
		TreeToListHelp(pRoot->left, pLeftHead, pLeftTail);
		pLeftTail->right = pRoot;
		pRoot->left = pLeftTail;
	}
	if (pRoot->right != NULL)
	{
		TreeToListHelp(pRoot->right, pRightHead, pRightTail);
		pRightHead->left = pRoot;
		pRoot->right = pRightHead;
	}
	if (pLeftHead != NULL)
	{
		pHead = pLeftHead;
	}
	else
	{
		pHead = pRoot;
	}
	if (pRightTail != NULL)
	{
		pTail = pRightTail;
	}
	else
	{
		pTail = pRoot;
	}
}


void Test_27_BinaryTreeToList()
{
	TreeNode n5(5);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n11(11);

	TreeNode n6(6, NULL, &n7);
	TreeNode n10(10, &n9, &n11);	
	TreeNode n8(8, &n6, &n10);

	TreeNode *pAns = BinaryTreeToList(&n6);
}
