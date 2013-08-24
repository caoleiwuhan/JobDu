#include <iostream>
#include <vector>

#include "23_PrintBinaryTreeInLevel.h"

using namespace std;

void PrintBinaryTreeInLevel(TreeNode *pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	vector<TreeNode *> vec;
	int start = 0;
	vec.push_back(pNode);
	while (start < vec.size())
	{
		TreeNode *pCur = vec[start];
		++start;
		cout << pCur->key << ' ';
		if (pCur->left)
		{
			vec.push_back(pCur->left);
		}
		if (pCur->right)
		{
			vec.push_back(pCur->right);
		}		
	}
}
void Test_23_PrintBinaryTreeInLevel()
{
	TreeNode n5(5);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n11(11);

	TreeNode n6(6, &n5, &n7);
	TreeNode n10(10, &n9, &n11);
	
	TreeNode n8(8, &n6, &n10);

	PrintBinaryTreeInLevel(&n8);

}
