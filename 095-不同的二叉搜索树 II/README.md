# 095-不同的二叉搜索树 II

## 题目

leetcode：[095-不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

## 分治

参考[LeetCode评论区 宝宝可乖了 的评论](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/comments/41407)。

- 对于连续整数序列`[left, right]`中的一点`i`，若要生成以`i`为根节点的BST，则有如下规律：
  - `i`左边的序列可以作为左子树结点，且左儿子可能有多个，所以有`vector<TreeNode *> left_nodes = generate(left, i - 1);`；
  - `i`右边的序列可以作为右子树结点，同上所以有`vector<TreeNode *> right_nodes = generate(i + 1, right);`；
  - 产生的以当前`i`为根结点的BST（子）树有`left_nodes.size() * right_nodes.size()`个，遍历每种情况，即可生成以`i`为根节点的BST序列；
  - 然后以`for`循环使得`[left, right]`中每个结点都能生成子树序列。
- 一旦`left`大于`right`，则说明这里无法产生子树，所以此处应该是作为空结点返回：`ans.push_back(NULL); return ans;`；
- 返回`[left, right]`中生成的所有子树序列`ans`。

```c++
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        } else {
            return generateTrees(1, n);
        }
    }

private:
    // 生成二叉搜索树集合
    vector<TreeNode*> generateTrees(int left, int right) {
        vector<TreeNode*> res;
        if (left > right) {
            res.push_back(NULL); // 空
            return res;
        }

        for (int i = left; i <= right; ++i) {
            vector<TreeNode*> leftTrees = generateTrees(left, i - 1); // 左子树集合
            vector<TreeNode*> rightTrees = generateTrees(i + 1, right); // 右子树集合

            // 以 i 为根结点，组合不同的左子树和右子树，生成不同的二叉搜索树
            for (auto leftTree : leftTrees) {
                for (auto rightTree : rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};
```

## 动态规划

## 思路1

参考[LeetCode题解](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-7/)，思路跟递归的思路一样，但是使用了迭代的方式实现。

```c++
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*> > dp(n + 1);
        if (n == 0) {
            return dp[n];
        }
        dp[0].push_back(NULL);


        // 长度为 1 到 n
        for (int len = 1; len <= n; ++len) {
            for (int root = 1; root <= len; ++root) {
                int left = root - 1; // 左子树结点数
                int right = len - root; // 右子树结点数
                for (auto leftTree : dp[left]) {
                    for (auto rightTree : dp[right]) {
                        TreeNode* rootNode = new TreeNode(root);
                        rootNode->left = leftTree;
                        // 克隆右子树并且加上偏移
                        rootNode->right = clone(rightTree, root);
                        dp[len].push_back(rootNode);
                    }
                }
            }
        }

        return dp[n];
    }

private:
    // 克隆树，并更新结点的值为原值加上偏移
    TreeNode* clone(TreeNode* root, int offset) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* newRoot  = new TreeNode(root->val + offset);
        newRoot->left = clone(root->left, offset);
        newRoot->right = clone(root->right, offset);

        return newRoot;
    }
};
```


### 思路2

参考[LeetCode评论区 气和 的Java实现](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/comments/51519)。暂时还看不懂，mark一下。

思路：

- 从小往大生成，新来一数，肯定比现有的节点都大 ，那么n可以成为现在所有树的父节点，并且他们都是n的左子树。
- 第二步就是沿着现有子树的右侧尝试不断插入。 如果插入以后，n还有子树，那么这些子树都是n的左子树。

```java
class Solution {
    public List<TreeNode> generateTrees(int n) {
      List<TreeNode> list=new ArrayList<>();
        if(n<=0){
            return list;
        }
        //初始化list，将1加入list
        list.add(new TreeNode(1));
        //从2开始进行插入
        for(int i=2;i<=n;i++){
            //1.寻找全部的右子树
            int size=list.size();
            //修改列表中的所有树
            for(int j=0;j<size;j++){
                TreeNode tmpNode=list.get(j);
                TreeNode diNode=tmpNode;
                int x=1;
                //查找有多少个右节点
                while(diNode.right!=null){
                    diNode=diNode.right;
                   x++;
                }
                //进行复制和插值
                for(int c=1;c<=x;c++){
                    list.add(clone(tmpNode,c,i));
                }
            }
            //进行上文提到的第一步操作
            for(int j=0;j<size;j++){
                TreeNode tmpNode=new TreeNode(i);
                tmpNode.left=list.get(j);
                list.set(j,tmpNode);
            }
        }
        return list;
    }

    // 从node开始复制，复制x层，加入的数据为n
    private TreeNode clone(TreeNode node,int x,int n){
        TreeNode headNode=new TreeNode(node.val);
        headNode.left=node.left;
        TreeNode tmpNode=node,workNode=headNode;
        for(int i=1;i<x;i++){
            tmpNode=tmpNode.right;
            //复制下一层节点
            TreeNode newNode=new TreeNode(tmpNode.val);
            newNode.left=tmpNode.left;
            workNode.right=newNode;
            workNode=workNode.right;
        }

        //生成要插入的节点
        TreeNode nNode=new TreeNode(n);
        nNode.left=tmpNode.right;
        //将此节点插入
        workNode.right=nNode;
        return headNode;
    }
}
```

