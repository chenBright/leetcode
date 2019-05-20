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
        while (startNode->left != NULL) {
            Node *currentParent = startNode; // 当前父结点
            Node *lastParent = NULL; // 上一个父结点
            // 因为是完全二叉树，所以只要有一个结点为空，都不需要处理，next 默认为 NULL
            while (currentParent != NULL && currentParent->left != NULL && currentParent->right != NULL) {
                // 两棵子树之间相连
                if (lastParent != NULL) {
                    lastParent->right->next = currentParent->left;
                }
                // 连接左右结点
                currentParent->left->next = currentParent->right;
                lastParent = currentParent;
                currentParent = currentParent->next;
            }
            startNode = startNode->left; // 下一层
        }

        return root;
    }
};
