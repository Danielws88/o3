#include <iostream>
#include <time.h>
#include "Tree.h"
#include "Graph.h"

using namespace std;

int main()
{
    srand(time(0));

    //Tree tree;

    //TreeNode* a = tree.insert(1);
    //TreeNode* b = tree.insert(2, a);
    //TreeNode* c = tree.insert(3, a);
    //TreeNode* d = tree.insert(4, b);
    //TreeNode* e = tree.insert(5, b);
    //TreeNode* f = tree.insert(6, c);
    //TreeNode* g = tree.insert(7, f);
    //TreeNode* h = tree.insert(8, g);
    //TreeNode* i = tree.insertRandom(9);

    //tree.breadthTraversal();
    //tree.deleteNode(g);
    //tree.breadthTraversal();

    //cout << tree.getParent(g)->data << endl;

    //if (tree.isLeaf(a)) {
    //    cout << 1 << endl;
    //}
    //else {
    //    cout << 2 << endl;
    //}

    Graph graph;

    GraphNode* node1 = graph.insertNode(1);
    GraphNode* node2 = graph.insertNode(2);
    GraphNode* node3 = graph.insertNode(3);
    GraphNode* node4 = graph.insertNode(4);
    GraphNode* node5 = graph.insertNode(5);

    graph.insertEdge(node1, node2);
    graph.insertEdge(node1, node3);
    graph.insertEdge(node2, node4);
    graph.insertEdge(node3, node5);

    graph.breadthFirstTraversal();

	return 0;
}
