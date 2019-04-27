#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */