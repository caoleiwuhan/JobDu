#include <iostream>

#include "18_IsSubTree.h"

using namespace std;


bool IsSubTree(TreeNode *pA, TreeNode *pB)
{
	if (pA == NULL && pB == NULL)
	{
		return true;
	}
	if (pA == NULL && pB != NULL)
	{
		return false;
	}
	if (pA != NULL && pB == NULL)
	{
		return true;
	}
	if (pA->key == pB->key)
	{
		if (IsSameTree(pA, pB))
		{
			return true;
		}
	}
	if (IsSubTree(pA->left, pB) || IsSubTree(pA->right, pB))
	{
		return true;
	}
	return false;
}
bool IsSameTree(TreeNode *pTree, TreeNode *pTobe)
{
	if (pTobe == NULL)
	{
		return true;
	}
	if (pTree == NULL)
	{
		return false;
	}
	if (pTree->key != pTobe->key)
	{
		return false;
	}
	if (IsSameTree(pTree->left, pTobe->left) && IsSameTree(pTree->right, pTobe->right))
	{
		return true;
	}
	return false;
}
void Test_18_IsSubTree()
{
	TreeNode n71(7);
	TreeNode n72(7);
	TreeNode n4(4);
	TreeNode n2(2, &n4, &n71);
	TreeNode n9(9);

	TreeNode n81(8, &n9, &n2);
	TreeNode n82(8, &n81, &n72);
	
	TreeNode n92(9);
	TreeNode n22(2);
	TreeNode n83(8, &n92, &n22);
	
	cout << IsSubTree(&n82, &n83) << endl;


}