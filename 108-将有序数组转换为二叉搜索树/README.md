# 108-将有序数组转换为二叉搜索树

## 题目

leetcode：[108-将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

## 思路

1. 选取数组中间的结点作为根结点。
2. 根结点左边部分作为左子树，右边部分作为右子树。

递归步骤1、2。

该方法的时间复杂度为***O(logn)***。

```c++
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) {
            return NULL;
        }

        TreeNode *root = sortedArrayToBST(nums, 0, nums.size() - 1);
        
        return root;
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &nums, int low, int high) {
        if (low > high) {
            return NULL;
        }

        int mid = (low + high) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, low, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, high);

        return node;
    }
};
```