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
