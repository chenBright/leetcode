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

class Solution {
public:
    Node* connect(Node *root) {
        preorder(root);
        return root;
    }

private:
    void preorder(Node *node) {
        // 因为是完全二叉树，所以只要有一个结点为空，都不需要处理，next 默认为 NULL
        if (node == NULL || node->left == NULL || node->right == NULL) {
            return;
        }

        node->left->next = node->right; // 连接左右结点
        // 连接右边相邻的子树
        if (node->next != NULL) {
            node->right->next = node->next->left;
        }

        preorder(node->left);
        preorder(node->right);
    }
};
