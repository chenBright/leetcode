# 113-路径总和 II

## 题目

leetcode：[113-路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

## 代码

```c++
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        pathSumRecursion(root, sum);
        return res;
    }

private:
    vector<int> temp;
    vector<vector<int> > res;

    void pathSumRecursion(TreeNode *root, int sum) {
        if (root == NULL) {
            return;
        }

        

        temp.push_back(root->val);

        int nextSum = sum - root->val;
        // 叶子结点且刚好总和等于 sum
        if (nextSum == 0 && root->left == NULL && root->right == NULL) {
            res.push_back(temp);
        }

        pathSumRecursion(root->left, nextSum);
        pathSumRecursion(root->right, nextSum);
        temp.pop_back(); // 弹出，将数组恢复到上一级调用时的状态
    }
};

```

