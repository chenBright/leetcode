#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct MyTreeNode {
    int val;
    int count; // 该树的结点数
    MyTreeNode *left;
    MyTreeNode *right;
    MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        MyTreeNode *newRoot = build(root);

        return helper(newRoot, k);
    }
private:
    // 建立一个二叉搜索树
    MyTreeNode* build(TreeNode *node) {
        if (node == NULL) {
            return NULL;
        }

        MyTreeNode *newNode = new MyTreeNode(node->val);

        newNode->left = build(node->left);
        newNode->right = build(node->right);
        
        // 左子树不为空，加上左子树的结点数
        if(node->left != NULL) {
            newNode->count += newNode->left->count;
        }


        // 右子树不为空，加上左子树的结点数
        if (node->right != NULL) {
            newNode->count += newNode->right->count;
        }

        return newNode;
    }

    int helper(MyTreeNode *node,  int k) {
        if (node->left != NULL) {
            // 如果左子树不为空
            int leftCount = node->left->count;
            if (k <= leftCount) { // 在该子树的左子树找到第k小的结点
                return helper(node->left, k);
            } else if (k > leftCount + 1) { // 在该子树的右子树找到第k小的结点
                return helper(node->right, k - leftCount - 1);
            } else { // 当前结点是第k小的结点
                return node->val;
            }
        } else {
            if (k == 1) {
                return node->val;
            } else { // 题目保证了 1 <= k <= 结点数，所以 node->right != NULL
                return helper(node->right, k - 1);
            }
        }
    }
};