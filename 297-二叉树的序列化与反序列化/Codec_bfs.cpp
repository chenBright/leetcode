#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
// 层序遍历
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        if (root != NULL) {
            q.push(root);
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node != NULL) {
                out << node->val << ' ';
                q.push(node->left);
                q.push(node->right);
            } else {
                out << "# ";
            }
        }
        
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        istringstream in(data);
        string val;
        in >> val;
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // 左子树
            if (!(in >> val)) {
                break;
            }
            if (val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // 右子树
            if (!(in >> val)) {
                break;
            }
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));