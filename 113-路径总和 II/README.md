# 113-路径总和 II

## 题目

leetcode：[113-路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

## 代码

```c++
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }

        vector<int> tmp;
        helper(root, sum, result, tmp);

        return result;
    }
private:
    void helper(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& tmp) {
        if (root == NULL) {
            return;
        }

        tmp.push_back(root->val);
        sum -= root->val;
        if (root->left == NULL && root->right == NULL && sum == 0) {
            result.push_back(tmp);
        }

        helper(root->left, sum, result, tmp);
        helper(root->right, sum, result, tmp);

        tmp.pop_back(); // 弹出，将数组恢复到上一级调用时的状态
    }
};
```

