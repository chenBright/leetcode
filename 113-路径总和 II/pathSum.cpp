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
