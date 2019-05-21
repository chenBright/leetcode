# 117-填充每个节点的下一个右侧节点指针 II

## 题目

leetcode：[117-填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)

## 层序遍历

使用层序遍历，一层一层连接。具体实现与[116-填充每个节点的下一个右侧节点指针](../116-填充每个节点的下一个右侧节点指针)差不多。

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
        if (node == NULL) {
            return;
        }

        Node *currentParent = node; // 当前父结点
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
        // 下一层
        bfs(nextNode);
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
```

## 类似先序遍历

参考[LeetCode评论区 Angus-Liu 的思路](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/comments/45416)。

```c++
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
```



