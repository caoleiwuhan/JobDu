#include <iostream>
#include <vector>

#include "6_RebuildBinaryTree.h"

using namespace std;

TreeNode *FirstCommonParent(TreeNode *pRoot, TreeNode *pNode1, TreeNode *pNode2);

bool FindPathToListNode(TreeNode *pRoot, TreeNode *pNode, vector<TreeNode *> &vec);


int ContinueMaxNumber(char *outputStr, char *inuptStr);