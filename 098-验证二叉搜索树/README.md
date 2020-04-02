# 098-验证二叉搜索树

## 题目

leetcode：[098-验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)

## 中序遍历

二叉搜索树***中序遍历***的序列是一个***升序序列***。所以，使用一个变量记录上一访问结点的值，只要保证当前结点值大于上一结点值，知道遍历结束，则该二叉树是二叉搜索树。

### 递归实现

```c++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long lastValue = LONG_MIN; // 上一结点值。类型为 long，是为了避免 node->val = INT_MIN 出错的情况
        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        while (!nodeStack.empty() || node != NULL) {
            if (node != NULL) {
                nodeStack.push(node);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                if (node->val <= lastValue) {
                    return false;
                }
                lastValue = node->val;
                node = node->right;
            }
        }

        return true;
    }
};
```

### 非递归实现

```c++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long lastValue = LONG_MIN;
        return isValidBSTRecursion(root, lastValue);
    }
private:
    // lastValue：上一结点值。类型为 long，
    // 是为了避免 node->val = INT_MIN 出错的情况。
    bool isValidBSTRecursion(TreeNode *root, long& lastValue) {
        if (root == NULL) {
            return true;
        }

        bool leftResult = isValidBSTRecursion(root->left, lastValue);

        // 左子树不是二叉搜索树 或者 左结点值大于等于根结点值
        if (!leftResult || lastValue >= root->val) {
            return false;
        }
        lastValue = root->val;

        return isValidBSTRecursion(root->right, lastValue);
    }
};
```

