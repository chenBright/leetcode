#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// BFS
class Solution {
public:
    Node* cloneGraph(Node *node) {
        unordered_map<Node*, Node*> nodeMap;
        queue<Node*> nodeQueue;

        Node *newNode = new Node(node->val, vector<Node*>());
        nodeMap[node] = newNode;
        nodeQueue.push(node);
        while (!nodeQueue.empty()) {
            node = nodeQueue.front();
            nodeQueue.pop();

            for (const auto &neighbor : node->neighbors) {
                // 没有访问过，放入队列中，并且建立映射
                if (!nodeMap.count(neighbor)) {
                    nodeQueue.push(neighbor);
                    nodeMap[neighbor] = new Node(neighbor->val, vector<Node*>());
                }
                nodeMap[node]->neighbors.push_back(nodeMap[neighbor]);
            }
        }

        return newNode;
    }
};