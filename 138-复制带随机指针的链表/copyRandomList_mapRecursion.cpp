#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node *head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> nodeMap;
        return copyNode(head, nodeMap);
    }

private:
    Node *copyNode(Node *node, unordered_map<Node*, Node*> &nodeMap) {
        if (node == NULL) {
            return NULL;
        }

        if (nodeMap.count(node)) { // 已经拷贝过了，则直接返回
            return nodeMap[node];
        }

        Node *newNode = new Node(node->val, NULL, NULL);
        nodeMap[node] = newNode; // 标记为拷贝过
        newNode->next = copyNode(node->next, nodeMap);
        newNode->random = copyNode(node->random, nodeMap);

        return newNode;
    }
};