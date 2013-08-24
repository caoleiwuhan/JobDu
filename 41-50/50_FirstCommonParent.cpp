#include <iostream>
#include <vector>

#include "6_RebuildBinaryTree.h"
#include "50_FirstCommonParent.h"

using namespace std;

TreeNode *FirstCommonParent(TreeNode *pRoot, TreeNode *pNode1, TreeNode *pNode2)
{
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
	{
		return NULL;
	}
	vector<TreeNode *> pVec1;
	pVec1.push_back(pRoot);
	if (!FindPathToListNode(pRoot, pNode1, pVec1))
	{
		return false;
	}
	vector<TreeNode *> pVec2;
	pVec2.push_back(pRoot);
	if (!FindPathToListNode(pRoot, pNode2, pVec2))
	{
		return false;
	}
	int minLen = min(pVec1.size(), pVec2.size());
	TreeNode *pAns = pRoot;
	for (int i = 0; i < minLen; ++i)
	{
		if (pVec1[i] == pVec2[i])
		{
			pAns = pVec1[i];
		}
		else
		{
			break;
		}
	}
	return pAns;
}

bool FindPathToListNode(TreeNode *pRoot, TreeNode *pNode, vector<TreeNode *> &vec)
{
	if (pRoot == NULL)
	{
		return false;
	}
	if (pRoot == pNode)
	{		
		return true;
	}
	if (pRoot->left)
	{
		vec.push_back(pRoot->left);
		if (FindPathToListNode(pRoot->left, pNode, vec))
		{
			return true;
		}
		vec.erase(vec.end() - 1);
	}
	if (pRoot->right)
	{
		vec.push_back(pRoot->right);
		if (FindPathToListNode(pRoot->right, pNode, vec))
		{
			return true;
		}
		vec.erase(vec.end() - 1);
	}
	return false;
}

int ContinueMaxNumber(char *outputStr, char *inputStr)
{
	int nAns = 0;
	int nCurLen = 0;
	char *pCurStart = inputStr;
	char *pChar = inputStr;
	while (*pChar++)
	{
		if (isalpha(*pChar))
		{
			if (nCurLen > nAns)
			{
				nAns = nCurLen;
				outputStr = pCurStart;
			}
			nCurLen = 0;
		}
		if (isdigit(*pChar))
		{
			if (nCurLen == 0)
			{
				pCurStart = pChar;
			}
			++nCurLen;
		}		
	}
	if (nCurLen > nAns)
	{
		nAns = nCurLen;
		outputStr = pCurStart;
	}
	return nAns;
}