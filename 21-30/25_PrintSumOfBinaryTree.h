#include <iostream>
#include <vector>

#include "6_RebuildBinaryTree.h"

using namespace std;

void PrintSumOfBinaryTree(TreeNode *pNode, int sum);

void PrintSumDFS(TreeNode *pNode, int sum, vector<TreeNode *> &vec);

void PrintVecOfTreeNode(vector<TreeNode *> &vec, int start, int to);


void Test_25_PrintSumOfBinaryTree();

