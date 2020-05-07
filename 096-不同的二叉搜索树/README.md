# 096-不同的二叉搜索树

## 题目

leetcode：[096-不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)

## 思路

[LeetCode评论区 ThreeCold 的思路](https://leetcode-cn.com/problems/unique-binary-search-trees/comments/1198)：假设n个节点存在二叉排序树的个数是G(n)，1为根节点，2为根节点，...，n为根节点。当1为根节点时，其左子树节点个数为0，右子树节点个数为n-1。同理当2为根节点时，其左子树节点个数为1，右子树节点为n-2，所以可得`G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)`。

根据该思路，有两种实现方式：**记忆化搜索**和**动态规划**。

### 记忆化搜索

```c++
class Solution {
public:
    int numTrees(int n) {
        unordered_map<int, int> m;
        m[0] = 1;
        return numTrees(n, m);
    }
private:
    int numTrees(int n, unordered_map<int, int>& m) {
        if (m.count(n)) {
            return m[n];
        }

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            m[i - 1] = numTrees(i - 1, m);
            m[n - i] = numTrees(n - i, m);

            result += m[i - 1] * m[n - i];
        }

        m[n] = result;

        return result;
    }
};
```

### 动态规划

```c++
class Solution {
public:
    int numTrees(int n) {
        // dp[i] 表示 i 个结点的二叉搜索树的个数。
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // 结点 j 为根结点时，二叉搜索树的个数。
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
```

