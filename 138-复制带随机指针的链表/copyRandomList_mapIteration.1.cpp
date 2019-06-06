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
        Node *dummy = new Node();
        Node *newNode = dummy;
        Node *node = head;
        // 遍历拷贝结点，并生成源节点与拷贝结点的映射
        while (node != NULL) {
            newNode->next = new Node(node->val, NULL, NULL);
            newNode = newNode->next;
            nodeMap.insert(make_pair(node, newNode));
            node = node->next;
        }

        node = head;
        // 设置 random 指针
        while (node != NULL) {
            Node *randomNode = node->random;
            nodeMap[node]->random = nodeMap[randomNode];
            node = node->next;
        }

        return dummy->next;
    }
};