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
        if (root == NULL) {
            return root;
        }

        if (root->left != NULL) {
            if (root->right != NULL) { // 若右子树不为空，则左子树的 next 即为右子树
                root->left->next = root->right;
            } else { // 若右子树为空，则右子树的 next 由根节点的 next 得出
                root->left->next = nextNode(root->next);
            }
        }
        if (root->right != NULL) { // 右子树的 next 由根节点的 next 得出
            root->right->next = nextNode(root->next);
        }

        /**
         * 先确保 root.right 下的节点的已完全连接，因 root.left 下的节点的连接
         * 需要 root.left.next 下的节点的信息，若 root.right 下的节点未完全连
         * 接（即先对 root.left 递归），则 root.left.next 下的信息链不完整，将
         * 返回错误的信息。可能出现的错误情况如下图所示。此时，底层最左边节点将无
         * 法获得正确的 next 信息：
         *                  o root
         *                 / \
         *     root.left  o —— o  root.right
         *               /    / \
         *              o —— o   o
         *             /        / \
         *            o        o   o
         */
        connect(root->right);
        connect(root->left);

        return root;
    }

private:
    Node* nextNode(Node *node) {
        while (node != NULL) {
            if (node->left != NULL) {
                return node->left;
            } else if (node->right != NULL) {
                return node->right;
            }
            node = node->next;
        }

        return NULL;
    }
};
