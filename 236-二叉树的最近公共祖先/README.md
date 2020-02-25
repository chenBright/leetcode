# 236-二叉树的最近公共祖先

## 题目

leetcode：[236-二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

## 后序遍历

后序遍历可以记录从根结点到目标结点的路径。

### 递归

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pNodes;
        if (!postOrder(root, p, pNodes)) {
            return NULL;
        }

        stack<TreeNode*> qNodes;
        if (!postOrder(root, q, qNodes)) {
            return NULL;
        }

        TreeNode *ancestor = NULL;
        // 栈顶到栈底为根结点到目标结点。
        // 查找最后一个相等的结点，即为最近公共祖先。
        while (!pNodes.empty() && !qNodes.empty()) {
            if (pNodes.top() != qNodes.top()) {
                break;
            }
            ancestor = pNodes.top();
            pNodes.pop();
            qNodes.pop();
        }

        return ancestor;
    }

private:
    // 后序遍历查找目标结点
    bool postOrder(TreeNode* root, TreeNode* target, stack<TreeNode*>& nodes) {
        if (root == NULL) {
            return false;
        }

        if (root == target
            || postOrder(root->left, target, nodes)
            || postOrder(root->right, target, nodes)) {
            nodes.push(target);
            return true;
        }

        return false;
    }
};
```

更简洁的实现，参考[博客](https://www.cnblogs.com/grandyang/p/4641968.html)。

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL) {
            return root;
        }

        // 当 left 不为空，right 为空，则 left 是 right 的父结点
        // 当 right 不为空，left 为空，则 right 是 left 的父结点
        // 否则，p、q 都不是 root 的子孙结点
        return left != NULL ? left : right;
    }
};
```



### 迭代

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> pNodes;
        if (!postOrderIteration(root, p, pNodes)) {
            return NULL;
        }

        deque<TreeNode*> qNodes;
        if (!postOrderIteration(root, q, qNodes)) {
            return NULL;
        }

        TreeNode *ancestor = NULL;
        // 栈顶到栈底为根结点到目标结点。
        // 查找最后一个相等的结点，即为最近公共祖先。
        while (!pNodes.empty() && !qNodes.empty()) {
            if (pNodes.front() != qNodes.front()) {
                break;
            }
            ancestor = pNodes.front();
            pNodes.pop_front();
            qNodes.pop_front();
        }

        return ancestor;
    }

private:
    // 后序遍历查找目标结点
    bool postOrderIteration(TreeNode* root, TreeNode* target, deque<TreeNode*>& nodes) {
        if (root == NULL) {
            return false;
        }

        TreeNode *node = root;
        TreeNode *lastNode = NULL;
        while (!nodes.empty() || node != NULL) {
           if (node != NULL) { // 一直走到最左边
                nodes.push_back(node);
                if (node == target) {
                    return true;
                }
                node = node->left;
            } else {
                node = nodes.back();
                if (node->right != NULL && node->right != lastNode) {
                    node = node->right;
                } else {
                    nodes.pop_back();
                    /**
                     * 将node设为 NULL，表示子树已处理完，在下一循环处理栈中的结点（即该子树的父结点）
                     * 否则，又重新回到“一直走到最左边”的步骤，导致死循环
                     */
                    lastNode = node;
                    node = NULL;
                }
            }
        }

        return false;
    }
};
```

## 使用父指针迭代

参考[LeetCode官方题解——“使用父指针迭代”](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetcod)。

- 从根节点开始遍历树。
- 在找到`p`和`q`之前，将父指针存储在字典中。
- 一旦我们找到了`p`和`q`，我们就可以使用父亲字典获得`p`的所有祖先，并添加到一个称为祖先的集合中。
- 同样，我们遍历节点`q`的祖先。如果祖先存在于为`p`设置的祖先中，这意味着这是`p`和`q`之间的第一个共同祖先（同时向上遍历），因此这是最近公共祖先节点。


```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> childToParent; // <子结点 , 父结点>
        childToParent[root] = NULL;

        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        // 层序遍历
        while (childToParent.count(p) == 0 || childToParent.count(q) == 0) {
            TreeNode *node = nodeQ.front();
            nodeQ.pop();

            if (node->left != NULL) {
                childToParent[node->left] = node;
                nodeQ.push(node->left);
            }

            if (node->right != NULL) {
                childToParent[node->right] = node;
                nodeQ.push(node->right);
            }
        }

        unordered_set<TreeNode*> parentSet;
        // 找出 p 的所有父结点
        while (p != NULL) {
            parentSet.insert(p);
            p = childToParent[p];
        }

        // 第一个存在于 parentSet 的 q 的父结点，即为最近公共祖先
        while (parentSet.count(q) == 0) {
            q = childToParent[q];
        }

        return q;
    }
};
```

