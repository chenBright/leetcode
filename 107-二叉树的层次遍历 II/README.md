# 107-二叉树的层次遍历 II

## 题目

leetcode：[107-二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/submissions/)

## 思路

该题目与[102-二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)类似，只需要将结果逆序输出即可。

```c++
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> v; // 保存子结点
        vector<int> temp; // 暂存行结果
        stack<vector<int> > s; // 暂存所有结果
        while (!q.empty()) {
            // 一次性处理一行
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != NULL) {
                    v.push_back(node->left);
                }
                if (node->right != NULL) {
                    v.push_back(node->right);
                }
            }
            for (vector<TreeNode*>::iterator it = v.begin(); it != v.end(); ++it) {
                q.push(*it);
            }

            s.push(temp); // 保存结果
            temp.clear();
            v.clear();
        }

        // 出栈，复制到res中，达到逆序的效果
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};
```

