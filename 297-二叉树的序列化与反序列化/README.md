# 297-二叉树的序列化与反序列化

## 题目

leetcode：[297-二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/submissions/)

## 先序遍历

```c++
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);

        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root != NULL) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(in);
        node->right = deserialize(in);

        return node;
    }
};
```

## 层序遍历

```c++
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
```

