#include <iostream>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// 层序遍历 非递归实现
class Solution {
public:
    Node* connect(Node *root) {
        if (root == NULL) {
            return root;
        }

        Node *startNode = root;
        // 层序遍历
        while (startNode != NULL) {
            Node *currentParent = startNode; // 当前父结点
            Node *currentNode = NULL; // 当前连接结点
            Node *nextNode = NULL; // 下一层的第一个结点
            while (currentParent != NULL) {
                if (currentParent->left != NULL) {
                    if (currentNode != NULL) {
                        currentNode->next = currentParent->left;
                        currentNode = currentNode->next;
                    } else {
                        currentNode = currentParent->left;
                        nextNode = currentParent->left;
                    }
                }
                
                if (currentParent->right != NULL) {
                    if (currentNode != NULL) {
                        currentNode->next = currentParent->right;
                        currentNode = currentNode->next;
                    } else {
                        currentNode = currentParent->right;
                        nextNode = currentParent->right;
                    }
                }
                currentParent = currentParent->next;
            }
            startNode = nextNode; // 下一层
        }

        return root;
    }
};
