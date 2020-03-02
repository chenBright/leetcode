#include <vector>
using namespace std;

struct BSTNode {
    int val;
    int count; // 左子树的结点数
    BSTNode* left;
    BSTNode* right;
    BSTNode(int v) : val(v), count(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length, 0);
        if (nums.empty()) {
            return result;
        }

        BSTNode* root = NULL;
        // 从后往前构建二叉搜索树
        for (int i = length - 1; i >=  0; --i) {
            BSTNode* node = new BSTNode(nums[i]);
            root = insertNode(root, node, result[i]);
        }

        return result;
    }

private:
    BSTNode* insertNode(BSTNode* root, BSTNode* node, int& count) {
        if (root == NULL || node == NULL) {
            return node;
        }

        if (root->val >= node->val) {
            // 结点值等于 root->val 的结点也放在左子树上。
            ++root->count; // 在左子树插入一个结点，count 加一。
            root->left = insertNode(root->left, node, count);
        } else {
            count += root->count + 1; // 加上 root 及其 左子树的个数
            root->right = insertNode(root->right, node, count);
        }

        return root;
    }
};
