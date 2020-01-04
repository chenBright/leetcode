# 1143-最长公共子序列

## 题目

leetcode：[1143-最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)

## 动态规划

参考[算法设计与分析](https://book.douban.com/subject/6434299/)P65和[LeetCode题解](https://leetcode-cn.com/problems/longest-common-subsequence/solution/dong-tai-gui-hua-zhi-zui-chang-gong-gong-zi-xu-lie/)。

### 二维dp数组

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.size();
        int length2 = text2.size();
        vector<vector<int> > dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    // dp[i][j] 肯定小于 dp[i + 1][j] 和 dp[i][j + 1]
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[length1][length2];
    }
};
```

### 一维dp数组

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.size();
        int length2 = text2.size();
        vector<int> dp(length2 + 1, 0); // 将 dp 数组压缩档一维
        for (int i = 0; i < length1; ++i) {
            int last = dp[0]; // 记录上一行左上角的值，即 [i - 1][j - 1] 位置上的值。
            int now = 0;
            for (int j = 0; j < length2; ++j) {
                now = dp[j + 1]; // 记录上一行 j + 1 位置的值。
                if (text1[i] == text2[j]) {
                    dp[j + 1] = last + 1;
                } else {
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                last = now;
            }
        }

        return dp[length2];
    }
};
```

