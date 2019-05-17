# 105-从前序与中序遍历序列构造二叉树

## 题目

leetcode：[105-从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


## 分析

给定二叉树前序遍历序列和中序遍历序列，可以唯一确定一颗二叉树。其中的规律为，**前序遍历序列的第一个元素为二叉树的根结点，在中序遍历序列中，根结点左边的元素为左子树的结点，右边的元素为右子树上的结点**。

算法流程：

1. 根据前序遍历序列的第一个元素确定根结点；
2. 在中序遍历序列中找到根结点元素，该元素左边的元素为左子树的中序遍历序列，右边的元素为右子树结点的中序遍历序列；
3. 假设步骤2中，左子树结点数为n，右子树结点数为m，则在前序遍历序列中，根结点元素之后n个元素为左子树的前序遍历序列，最后m个元素为右子树的前序遍历序列。
4. 构建根结点；
5. 根据得到左子树的前序遍历序列和中序遍历序列，递归构建左子树；
6. 根据右子树的的前序遍历序列和中序遍历序列，递归构建右子树。

```c++
class Solution {
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeRecursion(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeRecursion(vector<int> &preorder, int preLow, int preHigh, 
                            vector<int> &inorder, int inLow, int inHigh) {
        if (preLow > preHigh || inLow > inHigh) {
            return NULL;
        }

        if (preHigh - preLow != inHigh - inLow) {
            return NULL;
        }

        if (preorder.empty()) {
            return NULL;
        }

        int rootVal = preorder[preLow];
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
        root->left = buildTreeRecursion(preorder, preLow + 1, preLow + (rootIndex - inLow), inorder, inLow, rootIndex - 1);
        root->right = buildTreeRecursion(preorder, preLow + (rootIndex - inLow) + 1, preHigh, inorder, rootIndex + 1, inHigh);

        return root;
    }
};

```

