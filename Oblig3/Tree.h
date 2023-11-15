#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;


class Tree
{
private:
	TreeNode* root;

	int calculateSize(TreeNode* node);
	int calculateDepth(TreeNode* node);
	TreeNode* getRandomNode(TreeNode* node);
	
public:
	Tree();

	TreeNode* getRoot();
	TreeNode* getParent(TreeNode* node);
	vector <TreeNode*> getChildren(TreeNode* node);

	int getSize();
	int getDepth();

	bool isEmpty();
	bool isRoot(TreeNode* node);
	bool isLeaf(TreeNode* node);

	TreeNode* insert(int data, TreeNode* parent = nullptr);
	TreeNode* insertRandom(int data);
	void traverseForRandomNode(TreeNode* node, int targetIndex, int& currentIndex, TreeNode*& resultNode);

	void deleteNode(TreeNode* node);

	void breadthFirstTraversal();
	void traverseAndPrint(TreeNode* node);
};

