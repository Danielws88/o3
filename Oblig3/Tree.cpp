#include "Tree.h"

//Constructor
Tree::Tree()
	:root(nullptr){}

//Insertion functions
TreeNode* Tree::insert(int data, TreeNode* parent) {
	TreeNode* newNode = new TreeNode(data, parent);
	if (!root) {
		root = newNode;
	}
	else if (parent) {
		parent->addChild(newNode);
	}
	else {
		root->addChild(newNode);
	}
	return newNode;
}

TreeNode* Tree::insertRandom(int data){
	if (!root) {
		return insert(data);
	}
	else {
		TreeNode* randomNode = getRandomNode(root);
		return insert(data, randomNode);
	}
}
//Supplementary function to the one above
TreeNode* Tree::getRandomNode(TreeNode* node) {
	int randomNodeIndex = rand()%getSize();
	int currentIndex = 0;
	TreeNode* randomNode = nullptr;

	traverseForRandomNode(root, randomNodeIndex, currentIndex, randomNode);

	return randomNode;
}

//Breadth traversal for random node insertion
void Tree::traverseForRandomNode(TreeNode* node, int targetIndex, int& currentIndex, TreeNode*& resultNode) {
	if (!node) {
		return;
	}
	queue<TreeNode*> queue;
	queue.push(node);

	while (!queue.empty()) {
		TreeNode* current = queue.front();
		queue.pop();

		if (currentIndex == targetIndex) {
			resultNode = current;
			return;
		}

		currentIndex+=1;

		for (TreeNode* child : current->children) {
			queue.push(child);
		}
	}
}

//Node deletion
void Tree::deleteNode(TreeNode* node){
	if (!node || node == root) {
		return;
	}
	if (node) {
		for (TreeNode* child : node->children) {
			deleteNode(child);
		}
		if (node->parent) {
			TreeNode* parent = node->parent;

			auto it = find(parent->children.begin(), parent->children.end(), node);
			if (it != parent->children.end()) {
				parent->children.erase(it);
				delete node;
			}
		}
	}
}

//Breadth traversal and printing the node data
void Tree::breadthFirstTraversal(){
	traverseAndPrint(root);
}

void Tree::traverseAndPrint(TreeNode* node){
	if (!node) {
		return;
	}

	queue<TreeNode*> queue;
	queue.push(node);

	while (!queue.empty()) {
		TreeNode* temp = queue.front();
		queue.pop();

		cout << temp->data << " ";

		for (TreeNode* child : temp->children) {
			queue.push(child);
		}
	}
}

//Access functions
TreeNode* Tree::getRoot() {
	return root;
}

TreeNode* Tree::getParent(TreeNode* node) {
	if (!node||node==root) {
		return nullptr;
	}
	else {
		return node->parent;
	}
}

vector<TreeNode*> Tree::getChildren(TreeNode* node) {
	return node->children;
}

//Query functions
int Tree::getSize(){
	return calculateSize(root);
}

int Tree::calculateSize(TreeNode* node) {
	if (!node) {
		return 0;
	}

	int size = 1;

	for (TreeNode* child : node->children) {
		size += calculateSize(child);
	}

	return size;
}

int Tree::getDepth() {
	return calculateDepth(root);
}

bool Tree::isEmpty(){
	if (!root) {
		return true;
	}
	else {
		return false;
	}
}

bool Tree::isRoot(TreeNode* node){
	if (node == root) {
		return true;
	}
	else {
		return false;
	}
}

bool Tree::isLeaf(TreeNode* node){
	if (node->children.size()==0) {
		return true;
	}
	else {
		return false;
	}
}

int Tree::calculateDepth(TreeNode* node) {
	if (!node) {
		return 0;
	}

	int maxChildDepth = 0;

	for (TreeNode* child : node->children) {
		int childDepth = calculateDepth(child);
		maxChildDepth = max(maxChildDepth, childDepth);
	}

	return 1 + maxChildDepth;
}