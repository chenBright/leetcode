# 116-填充每个节点的下一个右侧节点指针

## 题目

leetcode：[116-填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)

## 层序遍历

使用层序遍历，一层一层连接。

### 递归实现

```c++
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
```

### 非递归实现

```c++
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
```

## 先序遍历

先连接当前结点的左右子结点，再处理当前结点右边相邻的子树，最后递归处理当前结点的左右子树。

```c++
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
```

