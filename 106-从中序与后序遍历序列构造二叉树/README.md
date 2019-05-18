# 106-从中序与后序遍历序列构造二叉树

## 题目

leetcode：[106-从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)


## 分析

给定二叉树前序遍历序列和中序遍历序列，可以唯一确定一颗二叉树。其中的规律为，**后序遍历序列的最后一个元素为二叉树的根结点，在中序遍历序列中，根结点左边的元素为左子树的结点，右边的元素为右子树上的结点**。

算法流程：

1. 根据后序遍历序列的最后一个元素确定根结点；
2. 在中序遍历序列中找到根结点元素，该元素左边的元素为左子树的中序遍历序列，右边的元素为右子树结点的中序遍历序列；
3. 假设步骤2中，左子树结点数为n，右子树结点数为m，则在后序遍历序列中，根结点元素之后n个元素为左子树的后序遍历序列，最后m个元素为右子树的后序遍历序列。
4. 构建根结点；
5. 根据得到左子树的后序遍历序列和中序遍历序列，递归构建左子树；
6. 根据右子树的的后序遍历序列和中序遍历序列，递归构建右子树。

```c++
class Solution {
public:
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeRecursion(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTreeRecursion(vector<int> &inorder, int inLow, int inHigh, 
                            vector<int> &postorder, int postLow, int postHigh) {
        if (inLow > inHigh || postLow > postHigh) {
            return NULL;
        }

        if (inHigh - inLow != postHigh - postLow) {
            return NULL;
        }

        if (postorder.empty()) {
            return NULL;
        }

        int rootVal = postorder[postHigh];
        int rootIndex = -1;
        for (int i = inLow; i <= inHigh; ++i) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        if (rootIndex < inLow || rootIndex > inHigh) {
            return NULL;
        }

        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTreeRecursion(inorder, inLow, rootIndex - 1, postorder, postLow, postLow + (rootIndex - 1 - inLow));
        root->right = buildTreeRecursion(inorder, rootIndex + 1, inHigh, postorder, postLow + (rootIndex - 1 - inLow) + 1, postHigh - 1);

        return root;
    }
};
```

