# 005-最长回文子串

## 题目

leetcode：[005-最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)


## 动态规划
详细分析参考[LeetCode 最长回文子串官方解答](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/)。

动态规划的时间复杂度为**O(n^2)**。

### 需要辅助数组

该方法的空间复杂度为**O(n^2)**。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        // indexs[0] 为回文串起点，indexs[1] 为回文串终点
        vector<int> indexs(2, 0);
        // dp[i][j] 表示 s[i...j] 是否是回文串
        vector<vector<bool> > dp(length, vector<bool>(length, false));

        for (int i = 0; i < length; ++i) { // i 为终点
            // j 为起点
            for (int j = i; j >= 0; --j) {
                /**
                 * 如果：
                 * 1. s[j] 和 s[i] 相邻 或者 i == j
                 * 或者
                 * 2. 在 s[j] 和 s[i] 相等的前提下，若 dp[j+1][i-1] 为真，即它们之间的字符串为回文串，
                 * 则 j 到 i 为回文串。
                 */
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j >= indexs[1] - indexs[0]) {
                        indexs[0] = j;
                        indexs[1] = i;
                    }
                }
            }
        }

        return s.substr(indexs[0], indexs[1] - indexs[0] + 1);
    }
};

```

### 不需要辅助数组

该方法的空间复杂度为***O(n^2)***。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        // indexs[0] 为回文串起点，indexs[1] 为回文串终点
        vector<int> indexs(2, 0);

        for (int i = 1; i < s.size(); ++i) {
            // 以 s[i] 为中心
            expandAroundCenter(s, i - 1, i + 1, indexs);
            // 以 s[i - 1]、s[i] 为中心
            expandAroundCenter(s, i - 1, i, indexs);
        }

        return s.substr(indexs[0], indexs[1] - indexs[0] + 1);
    }

private:
    // left 向左扩散，right 向又扩散，找到最长回文串。
    void expandAroundCenter(string &s, int left, int right, vector<int> &indexs) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        ++left;
        --right;
        if (right - left >= indexs[1] - indexs[0]) {
            indexs[0] = left;
            indexs[1] = right;
        }
    }
};
```

## Manacher算法

Manacher算法的时间复杂度为**O(n)**。

参考 LeetCode 题解：

- [动态规划、Manacher 算法](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/)
- [详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/)
- [5. 最长回文子串 C / C++](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/5-zui-chang-hui-wen-zi-chuan-cc-by-bian-bian-xiong/)