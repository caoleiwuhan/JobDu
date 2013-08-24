#include <iostream>

#include "6_RebuildBinaryTree.h"

using namespace std;

TreeNode *BinaryTreeToList(TreeNode *pRoot);

void TreeToListHelp(TreeNode *pRoot, TreeNode *&pHead, TreeNode *&pTail);

void Test_27_BinaryTreeToList();
