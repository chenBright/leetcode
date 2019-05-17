#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
