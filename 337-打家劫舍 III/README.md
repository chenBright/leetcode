# 337-打家劫舍 III

## 题目

leetcode：[337-打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)

## 动态规划

参考[博客](https://github.com/grandyang/leetcode/issues/337)、[LeetCode 中 CoderYQ 的评论](https://leetcode-cn.com/problems/house-robber-iii/comments/20026)和[LeetCode题解](https://leetcode-cn.com/problems/house-robber-iii/solution/jian-dan-gao-xiao-de-shu-zhuang-dpzi-di-xiang-shan/)。

核心的思路是有两种偷法：

1. 偷取当前结点和其左右子树的子树；
2. 不偷取当前结点，偷取左右子树。

在这两种偷法中，去最大值。

### 实现1

```c++
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;

        return rob(root, m);
    }
private:
    int rob(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (root == NULL) {
            return 0;
        }

        if (m.count(root)) {
            return m[root];
        }

        // 偷取当前结点
        int result1 = root->val;
        if (root->left != NULL) {
            result1 += rob(root->left->left, m) + rob(root->left->right, m);
        }
        if (root->right != NULL) {
            result1 += rob(root->right->left, m) + rob(root->right->right, m);
        }

        // 不偷取当前结点
        int result2 = rob(root->left, m) + rob(root->right, m);

        m[root] = max(result1, result2);

        return m[root];
    }
};
```

### 实现2

```c++
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = dfs(root);

        return max(result[0], result[1]);
    }
private:
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) {
            return vector<int>(2, 0);
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        // result[0] 表示不偷取当前结点的最大值。
        // result[1] 表示偷取当前结点的最大值。
        vector<int> result(2, 0);
        // 不偷取当前结点
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷取当前结点
        result[1] = left[0] + right[0] + root->val;

        return result;
    }
};
```

### 实现3

```c++
class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0;
        int r = 0;

        return helper(root, l, r);
    }
private:
    int helper(TreeNode* root, int&l, int& r) {
        if (root == NULL) {
            return 0;
        }

        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        l = helper(root->left, ll, lr);
        r = helper(root->right, rl, rr);

        // 偷取当前结点 或者 不偷取当前结点
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};
```

