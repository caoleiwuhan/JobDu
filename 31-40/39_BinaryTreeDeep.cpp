#include <iostream>

#include "39_BinaryTreeDeep.h"

using namespace std;

int BinaryTreeDeep(TreeNode *pNode)
{
	if (pNode == NULL)
	{
		return 0;
	}
	return max(BinaryTreeDeep(pNode->left), BinaryTreeDeep(pNode->right)) + 1;
}


void Test_39_BinaryTreeDeep()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n5.left = &n7;
	n3.right = &n6;



	cout << BinaryTreeDeep(&n1) << endl;
	cout << BinaryTreeDeep(&n2) << endl;
	cout << BinaryTreeDeep(&n3) << endl;
	cout << BinaryTreeDeep(&n4) << endl;
	cout << BinaryTreeDeep(&n5) << endl;
	cout << BinaryTreeDeep(&n6) << endl;
	cout << BinaryTreeDeep(&n7) << endl;
	cout << BinaryTreeDeep(NULL) << endl;
}

bool IsBalanceTree(TreeNode *pNode, int &deep)
{
	if (pNode == NULL)
	{
		deep = 0;
		return true;
	}
	int leftDeep = -1;
	int rightDeep = -1;
	if (IsBalanceTree(pNode->left, leftDeep) && IsBalanceTree(pNode->right, rightDeep))
	{
		if (abs(leftDeep - rightDeep) <= 1)
		{
			deep = max(leftDeep, rightDeep) + 1;
			return true;
		}
	}
	return false;
}