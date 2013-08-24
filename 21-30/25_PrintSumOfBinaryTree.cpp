#include <iostream>
#include <vector>


#include "25_PrintSumOfBinaryTree.h"

using namespace std;

void PrintSumOfBinaryTree(TreeNode *pNode, int sum)
{
	if (pNode == NULL)
	{
		return;
	}
	vector<TreeNode *> vec;
	vec.push_back(pNode);
	PrintSumDFS(pNode, sum, vec);
}

void PrintSumDFS(TreeNode *pNode, int sum, vector<TreeNode *> &vec)
{
	int size = vec.size();
	if (size != 0)
	{
		int tmp = 0;
		for (int i = size - 1; i >= 0; --i)
		{
			tmp += vec[i]->key;
			if (tmp == sum)
			{
				PrintVecOfTreeNode(vec, i, size - 1);
			}
		}
	}
	if (pNode->left)
	{
		vec.push_back(pNode->left);
		PrintSumDFS(pNode->left, sum, vec);
	}
	if (pNode->right)
	{
		vec.push_back(pNode->right);
		PrintSumDFS(pNode->right, sum, vec);
	}
	vec.pop_back();
}

void PrintVecOfTreeNode(vector<TreeNode *> &vec, int start, int to)
{
	int size = vec.size();
	if (start < 0 || start > to || to >= size)
	{
		throw std::exception("Invalid parameter in PrintVecOfTreeNode");
	}
	for (int i = start; i <= to; ++i)
	{
		cout << vec[i]->key << ' ';
	}
	cout << endl;
}

void Test_25_PrintSumOfBinaryTree()
{
	TreeNode n10(10);
	TreeNode n5(5);
	TreeNode n17(17);
	TreeNode n7(7);
	TreeNode n12(12);

	n10.left = &n5;
	n10.right = &n12;
	n5.left = &n17;
	n5.right = &n7;

	PrintSumOfBinaryTree(&n10, 22);
}
