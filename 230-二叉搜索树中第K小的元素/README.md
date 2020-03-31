# 230-二叉搜索树中第K小的元素

## 题目

leetcode：[230-二叉搜索树中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)

## 中序遍历

使用中序遍历，遍历到的第K个结点就是第K下的结点。

### 递归

```c++
class Solution {
public:
    int kthSmallest(TreeNode *root, int &k) {
        if (root == NULL) {
            return INT_MIN;
        }

        int left = kthSmallest(root->left, k);
        if (k == 0) { // 在左子树找到第k小的结点
            return left;
        }

        // 当前结点是第k小的结点
        if (--k == 0) {
            return root->val;
        }

         // 在右子树找到第k小的结点
        return kthSmallest(root->right, k);
    }
};
```

### 迭代

```c++
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        if (root == NULL) {
            return INT_MIN;
        }

        stack<TreeNode*> s;
        TreeNode *node = root;
        while (!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->left;
            } else {
                --k;
                // 当前结点是第k小的结点
                if (k == 0) {
                    return s.top()->val;
                }
                node = s.top()->right;
                s.pop();
            }
        }

        return INT_MIN;
    }
};
```

## 分治

先计算左右子树的结点数，设左子树的结点数为`n`：

- 如果`k <= n`，则递归地在左子树中查找第`k`小的结点（同样要先计算左子树根结点的左右子树的结点数）；
- 如果`k == n + 1`，则当前结点为第`k`小的结点；
- 如果`k > n + 1`，则递归地在右子树中查找第`n - k - 1`小的结点（同样要先计算右子树根结点的左右子树的结点数）。

```c++
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int n = count(root->left);
        if (k <= n) { // 在左子树找到第k小的结点
            return kthSmallest(root->left, k);
        } else if (k > n + 1) { // 在右子树找到第k小的结点
            return kthSmallest(root->right, k - n - 1);
        } else { // 当前结点是第k小的结点
            return root->val;
        }
    }
private:
    // 计算树的结点数
    int count(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        return 1 + count(node->left) + count(node->right);
    }
};
```

### 优化

参考[博客 解法四](https://www.cnblogs.com/grandyang/p/4620012.html)。

观察前面的方法，可以看出存在很多的重复计算。如果可以一次性计算好每个子树的结点数，就不用重复计算了。

新建一个二叉搜索树，该树的结点有一个属性用于保存该子树的结点数。

```c++
struct MyTreeNode {
    int val;
    int count; // 该树的结点数
    MyTreeNode *left;
    MyTreeNode *right;
    MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        MyTreeNode *newRoot = build(root);

        return helper(newRoot, k);
    }
private:
    // 建立一个二叉搜索树
    MyTreeNode* build(TreeNode *node) {
        if (node == NULL) {
            return NULL;
        }

        MyTreeNode *newNode = new MyTreeNode(node->val);

        newNode->left = build(node->left);
        newNode->right = build(node->right);

        // 左子树不为空，加上左子树的结点数
        if(node->left != NULL) {
            newNode->count += newNode->left->count;
        }


        // 右子树不为空，加上左子树的结点数
        if (node->right != NULL) {
            newNode->count += newNode->right->count;
        }

        return newNode;
    }

    int helper(MyTreeNode *node,  int k) {
        if (node->left != NULL) {
            // 如果左子树不为空
            int leftCount = node->left->count;
            if (k <= leftCount) { // 在该子树的左子树找到第k小的结点
                return helper(node->left, k);
            } else if (k > leftCount + 1) { // 在该子树的右子树找到第k小的结点
                return helper(node->right, k - leftCount - 1);
            } else { // 当前结点是第k小的结点
                return node->val;
            }
        } else {
            if (k == 1) {
                return node->val;
            } else { // 题目保证了 1 <= k <= 结点数，所以 node->right != NULL
                return helper(node->right, k - 1);
            }
        }
    }
};
```

