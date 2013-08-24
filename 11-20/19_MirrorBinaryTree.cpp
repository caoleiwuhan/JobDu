#include <iostream>

#include "19_MirrorBinaryTree.h"

using namespace std;


void MirrorBinaryTree(TreeNode *pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	TreeNode *pLeft = pNode->left;
	TreeNode *pRight = pNode->right;

	MirrorBinaryTree(pLeft);
	MirrorBinaryTree(pRight);
	pNode->left = pRight;
	pNode->right = pLeft;

}
void Test_19_MirrorBinaryTree()
{
	TreeNode n5(5);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n11(11);

	TreeNode n6(6, &n5, &n7);
	TreeNode n10(10, &n9, &n11);
	
	TreeNode n8(8, &n6, &n10);
	
	MirrorBinaryTree(&n8);
}