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

// 层序遍历 递归实现
class Solution {
public:
    Node* connect(Node *root) {
        bfs(root);
        return root;
    }

private:
    void bfs(Node *node) {
        // 因为是完全二叉树，所以只要有一个结点为空，都不需要处理，next 默认为 NULL
        if (node == NULL || node->left == NULL || node->right == NULL) {
            return;
        }

        Node *currentParent = node; // 当前父结点
        Node *lastParent = NULL; // 上一个父结点
        while (currentParent != NULL) {
            // 两棵子树之间相连
            if (lastParent != NULL) {
                lastParent->right->next = currentParent->left;
            }
            if (currentParent->left == NULL) {
                break;
            }
            // 连接左右结点
            currentParent->left->next = currentParent->right;
            if (currentParent->right == NULL) {
                break;
            }
            lastParent = currentParent;
            currentParent = currentParent->next;
        }
        // 下一层
        bfs(node->left);
    }
};
