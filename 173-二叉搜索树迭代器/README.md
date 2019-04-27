# 173-二叉搜索树迭代器

## 题目

leetcode：[173-二叉搜索树迭代器](https://leetcode-cn.com/problems/binary-search-tree-iterator/)

## 思路1

在构造函数中，直接中序遍历整棵二叉树，并保存结果。`next()` 和 `hasNext()` 操作的时间复杂度是 ***O(1)***，但空间复杂度为***O(n)***，其中n为二叉树结点数。

```c++
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        //  中序遍历，保存完整中序结果
        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) {
                nodeStack.push(node);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                q.push(node);
                node = node->right;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        if (!hasNext()) {
            return -1;
        }
        int n = q.front()->val;
        q.pop();

        return n;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

private:
    queue<TreeNode*> q;
};
```

## 思路2

在构造函数中，只需要找到二叉树的最左边结点，保存其路径。 `hasNext()` 操作的时间复杂度是 ***O(1)***，但空间复杂度为***O(h)***，其中h为树的高度。但`next()` 操作的时间复杂度不是严格为***O(1)***，因为得到next之后，还需要找到next结点右子树最左边的结点，并保存其路径。

```c++
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        // 一直找到最左边的结点，保存路径
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        if (!hasNext()) {
            return -1;
        }

        TreeNode *node = s.top();
        s.pop();
        int n = node->val;

        node = node->right;
        // 一直找到最左边的结点，保存路径
        while (node != NULL) {
            s.push(node);
            node = node->left;
        }

        return n;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

private:
    stack<TreeNode*> s;
};
```

