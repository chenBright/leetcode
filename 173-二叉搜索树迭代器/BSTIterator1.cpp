#include <stack>
#include <queue>
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */