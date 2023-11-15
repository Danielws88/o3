#pragma once
#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* parent;
    vector <TreeNode*> children;

    TreeNode(int value, TreeNode* parentNode = nullptr);

    void addChild(TreeNode* child);
};

