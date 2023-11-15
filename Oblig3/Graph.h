#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "GraphNode.h"

using namespace std;

class Graph
{
private:
	vector<GraphNode*> nodes;
	vector<vector<int>> adjacencyList;
public:
	Graph();

	int getData(GraphNode* node);
	vector<GraphNode*> getAdjacentNodes(GraphNode* node);
	vector<GraphNode*> getVerticies();
	vector<pair<int, int>> getEdges();

	int getSize();
	bool isEmpty();

	GraphNode* insertNode(int data);
	GraphNode* insertRandomNode(int data);
	void insertEdge(GraphNode* a, GraphNode* b);

	void deleteNode(GraphNode* node);
	void deleteEdge(GraphNode* a, GraphNode* b);

	void breadthFirstTraversal();
};

