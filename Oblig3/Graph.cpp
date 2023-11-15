#include "Graph.h"

//Constructor
Graph::Graph() {
    srand(time(0));
}

//Access functions
int Graph::getData(GraphNode* node){
    return node->data;
}

vector<GraphNode*> Graph::getAdjacentNodes(GraphNode* node){
    vector<GraphNode*> adjacentNodes;

    if (node) {
        int nodeIndex = -1;

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == node) {
                nodeIndex = i;
                break;
            }
        }
        if (nodeIndex != -1) {
            for (const auto& neighborIndex : adjacencyList[nodeIndex]) {
                adjacentNodes.push_back(nodes[neighborIndex]);
            }
        }
    }
    return adjacentNodes;
}

vector<GraphNode*> Graph::getVerticies(){
    return nodes;
}

vector<pair<int, int>> Graph::getEdges() {
    vector<pair<int, int>> edges;

    for (size_t i = 0; i < adjacencyList.size(); i++) {
        for (const auto& neighborIndex : adjacencyList[i]) {
            edges.emplace_back(i, neighborIndex);
        }
    }
    return edges;
}


//Insertion
GraphNode* Graph::insertNode(int data){
    GraphNode* newNode = new GraphNode(data);
    nodes.push_back(newNode);
    adjacencyList.emplace_back();
    return newNode;
}

GraphNode* Graph::insertRandomNode(int value) {
    if (nodes.empty()) {
        return insertNode(value);
    }
    else {
        int randomIndex = rand() % nodes.size();
        GraphNode* randomNode = nodes[randomIndex];
        GraphNode* newNode = insertNode(value);
        insertEdge(randomNode, newNode);
        return newNode;
    }
}

void Graph::insertEdge(GraphNode* a, GraphNode* b) {
    if (a && b) {
        int sourceIndex = -1;
        int destinationIndex = -1;

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == a) {
                sourceIndex = static_cast<int>(i);
            }
            if (nodes[i] == b) {
                destinationIndex = static_cast<int>(i);
            }
        }

        if (sourceIndex != -1 && destinationIndex != -1) {
            adjacencyList[sourceIndex].push_back(destinationIndex);
            adjacencyList[destinationIndex].push_back(sourceIndex);
        }
    }
}

//Deletion
void Graph::deleteNode(GraphNode* node) {
    if (!node) {
        return;
    }

    int nodeIndex = -1;
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == node) {
            nodeIndex = static_cast<int>(i);
            break;
        }
    }

    if (nodeIndex != -1) {
        // Remove edges associated with the node
        for (int i = 0; i < adjacencyList.size(); i++) {
            for (int j = 0; j < adjacencyList[i].size(); j++) {
                if (adjacencyList[i][j] == nodeIndex) {
                    adjacencyList[i].erase(adjacencyList[i].begin() + static_cast<int>(j));
                    break;
                }
            }
        }
        // Remove the node and its adjacency list
        delete nodes[nodeIndex];
        nodes.erase(nodes.begin() + nodeIndex);
        adjacencyList.erase(adjacencyList.begin() + nodeIndex);
    }
}

void Graph::deleteEdge(GraphNode* a, GraphNode* b) {
    if (a && b) {
        int sourceIndex = -1;
        int destinationIndex = -1;

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == a) {
                sourceIndex = static_cast<int>(i);
            }
            if (nodes[i] == b) {
                destinationIndex = static_cast<int>(i);
            }
        }

        if (sourceIndex != -1 && destinationIndex != -1) {
            // Find and remove the edge in both directions
            auto sourceEdgeIt = find(adjacencyList[sourceIndex].begin(), adjacencyList[sourceIndex].end(), destinationIndex);
            if (sourceEdgeIt != adjacencyList[sourceIndex].end()) {
                adjacencyList[sourceIndex].erase(sourceEdgeIt);
            }

            auto destinationEdgeIt = find(adjacencyList[destinationIndex].begin(), adjacencyList[destinationIndex].end(), sourceIndex);
            if (destinationEdgeIt != adjacencyList[destinationIndex].end()) {
                adjacencyList[destinationIndex].erase(destinationEdgeIt);
            }
        }
    }
}

//Query functions
int Graph::getSize() {
    return nodes.size();
}

bool Graph::isEmpty() {
    if (nodes.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}

//Breadth-First traversal
void Graph::breadthFirstTraversal() {
    if (nodes.empty()) {
        std::cout << "Graph is empty." << endl;
        return;
    }

    vector<bool> visited(nodes.size(), false);
    queue<GraphNode*> queue;


    queue.push(nodes[0]);
    visited[0] = true;

    std::cout << "Breadth-First Traversal:" << endl;

    while (!queue.empty()) {
        GraphNode* current = queue.front();
        queue.pop();

        cout << "Node: " << current->data << endl;

        // Enqueue adjacent nodes
        int currentIndex = -1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == current) {
                currentIndex = static_cast<int>(i);
                break;
            }
        }

        if (currentIndex != -1) {
            for (const auto& neighborIndex : adjacencyList[currentIndex]) {
                if (!visited[neighborIndex]) {
                    queue.push(nodes[neighborIndex]);
                    visited[neighborIndex] = true;

 
                    cout << "Edge: (" << current->data << ", " << nodes[neighborIndex]->data << ")" << endl;
                }
            }
        }
    }
}