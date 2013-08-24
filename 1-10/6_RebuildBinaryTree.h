#ifndef __6_REBUILD_BINARY_TREE__
#define __6_REBUILD_BINARY_TREE__

#include <iostream>
using namespace std;

struct TreeNode
{
	int key;
	TreeNode *left, *right;

	TreeNode(int _key) : key(_key), left(NULL), right(NULL) {}

	TreeNode(int _key, TreeNode *_left, TreeNode *_right) : key(_key), left(_left), right(_right) {}

};

TreeNode *RebuildBinaryTree(int len, int preArr[], int preStart, int inArr[], int inStart);

void Test_6_RebuildBinaryTree();




#endif