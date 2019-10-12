# 538-把二叉搜索树转换为累加树

## 题目

leetcode：[538-把二叉搜索树转换为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)

## 逆中序遍历

使用一个变量记录逆中序遍历累加的结果，并加到当前遍历的结点中。

### 递归1

```c++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);

        return root;
    }

private:
    void convert(TreeNode* root, int& sum) {
        if (root == NULL) {
            return;
        }

        convert(root->right, sum);
        root->val += sum;
        sum = root->val;
        convert(root->left, sum);

    }
};
```

### 递归2

```c++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);

        return root;
    }
private:
    int sum = 0;
};
```

## 迭代

```c++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        int sum = 0;
        TreeNode* node = root;
        while (!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->right;
            } else {
                node = s.top();
                s.pop();

                node->val += sum;
                sum = node->val;

                node = node->left;
            }
        }

        return root;
    }
};
```

