#include <iostream>

#include "6_RebuildBinaryTree.h"

using namespace std;


TreeNode *RebuildBinaryTree(int len, int preArr[], int preStart, int inArr[], int inStart)
{
	if (len <= 0)
	{
		return NULL;
	}
	if (len == 1)
	{
		if (preArr[preStart] != inArr[inStart])
		{
			throw std::exception("Invalid Tree, the key is not same");
		}
		TreeNode *p = new TreeNode(inArr[inStart]);
		return p;
	}
	// 找到子树的根在中序遍历中的位置
	int key = preArr[preStart];
	// 如果找不到说明出错，如果找到多个，也说明出错了
	int keyPos = -1;
	for (int i = 0; i < len; ++i)
	{
		if (inArr[inStart + i] == key)
		{
			if (keyPos != -1)
			{
				throw std::exception("The key is duplicate in tree!");				
			}
			keyPos = i;
		}
	}
	if (keyPos == -1)
	{
		throw std::exception("The key is not in tree!");
	}
	TreeNode *p = new TreeNode(key);
	TreeNode *left = RebuildBinaryTree(keyPos, preArr, preStart + 1, inArr, inStart);
	TreeNode *right = RebuildBinaryTree(len - keyPos - 1, preArr, preStart + 1 + keyPos, inArr, inStart + 1 + keyPos);
	p->left = left;
	p->right = right;

	return p;
}
void Test_6_RebuildBinaryTree()
{
	int preArr[] = 
	{
		1, 2, 4, 7, 3, 5, 6, 8
	};
	int inArr[] = 
	{
		4, 7, 2, 1, 3, 5, 3, 8, 6
	};
	try
	{
		TreeNode *pAns = RebuildBinaryTree(sizeof(preArr) / sizeof(int), preArr, 0, inArr, 0);
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
}