#include "TreeNode.h"

TreeNode::TreeNode(int data, TreeNode* parent)
	:data(data), parent(parent){}

void TreeNode::addChild(TreeNode* child) {
	child->parent = this;
	children.push_back(child);
}