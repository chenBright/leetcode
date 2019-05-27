#include <vector>
#include <unordered_map>
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

// DFS
class Solution {
public:
    Node* cloneGraph(Node *node) {
        return dfs(node);
    }

private:
    unordered_map<Node*, Node*> nodeMap; // 新旧结点 Map

    Node* dfs(Node *node) {
        if (node == NULL) {
            return NULL;
        }

        // 当前结点在 HashMap 中，即当前结点已经被克隆过
        if (nodeMap.count(node)) {
            return nodeMap[node];
        }

        Node *newNode = new Node(node->val, vector<Node*>());
        nodeMap[node] = newNode;
        for (const auto &neighbor : node->neighbors) {
            // 克隆 neighbor 结点
            newNode->neighbors.push_back(dfs(neighbor));
        }

        return newNode;
    }
};