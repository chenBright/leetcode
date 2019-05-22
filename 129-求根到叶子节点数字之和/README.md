# 129-求根到叶子节点数字之和

## 题目

leetcode：[129-求根到叶子节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/)

## 先序遍历

## 递归实现

1. 先遍历根节点；
2. 遍历左子树，递归遍历左子树的时候，把走当前路径的数字带到左子树的求解中；
3. 遍历右子树，递归遍历右子树的时候，把走当前路径的数字带到右子树的求解中；
4. 更新总的和。

```c++
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        sumNumbersRecursion(root, 0);
        return sum;
    }

private:
    int sum;
    void sumNumbersRecursion(TreeNode *node, int subSum) {
        if (node == NULL) {
            return;
        }

        int s = subSum * 10 + node->val;
        if (node->left != NULL) {
            sumNumbersRecursion(node->left, s);
        }

        if (node->right != NULL) {
            sumNumbersRecursion(node->right, s);
        }

        if (node->left == NULL && node->right == NULL) {
            sum += s;
        }
        
    }
};
```

## 非递归实现

除了使用一个常规的栈保存结点，还需要一个栈保存值（遍历到当前结点的和）。

注：该实现思路与我自己平时的实现（"转向"）不一样。

```c++
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == NULL) {
            return sum;
        }

        // 每个结点对应着一个和
        stack<TreeNode*> nodeStack; // 结点栈
        stack<int> valueStack; // “和”栈
        nodeStack.push(root);
        valueStack.push(root->val);

        // 先序遍历
        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            int value = valueStack.top();
            valueStack.pop();

            if (node->left == NULL && node->right == NULL) {
                sum += value;
            }

            if (node->right != NULL) {
                nodeStack.push(node->right);
                valueStack.push(value * 10 + node->right->val);
            }
            if (node->left !=  NULL) {
                nodeStack.push(node->left);
                valueStack.push(value * 10 + node->left->val);
            }
        }

        return sum;
    }
};
```

