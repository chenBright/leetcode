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

        Node *node = head;
        Node *newNode = NULL;
        // 将拷贝结点插入到源结点后面，例如 1->2->3  ==>  1->1'->2->2'->3->3'
        while (node != NULL) {
            newNode = new Node(node->val, node->next, NULL);
            node->next = newNode;
            node = node->next->next;
        }

        node = head;
        // 连接 random 指针
        while (node != NULL) {
            if (node->random != NULL) {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }

        Node *newHead = head->next;
        node = head;
        newNode = newHead;
        // 拆开两个链表
        while (node != NULL) {
            node->next = newNode->next;
            node = node->next;
            if (node != NULL) {
                newNode->next = node->next;
                newNode = newNode->next;
            }
        }

        return newHead;
    }
};