# 005-最长回文子串

## 题目

leetcode：[005-最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)


## 动态规划
详细分析参考[LeetCode 最长回文子串官方解答](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/)。

动态规划的时间复杂度为***O(n^2)***。

### 需要辅助数组

该方法的空间复杂度为***O(n^2)***。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 0 || length == 1) {
            return s;
        }

        // indexs[0]为回文串起点，indexs[1]为回文串终点
        vector<int> indexs(2, 0);
        // dp[i][j] 表示s[i...j]是否是回文串
        vector<vector<bool> > dp(length, vector<bool>(length, false));
        
        for (int i = 0; i < length; ++i) { // i为终点
            int j = i; // j为起点
            while (j >= 0) {
                /**
                 * 如果：
                 * 1. s[j]和s[i]相邻 或者 i == j
                 * 或者
                 * 2. 在s[j]和s[i]相等的前提下，若dp[j+1][i-1]为真，即它们之间的字符串为回文串，
                 * 则j到i为回文串
                 */
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j >= indexs[1] - indexs[0]) {
                        indexs[0] = j;
                        indexs[1] = i;
                    }
                }
                --j;
            }
        }

        return string(s.begin() + indexs[0], s.begin() + indexs[1] + 1);
    }
};
```

### 不需要辅助数组

该方法的空间复杂度为***O(n)***。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 0 || length == 1) {
            return s;
        }

        // indexs[0]为回文串起点，indexs[1]为回文串终点
        vector<int> indexs(2, 0);

        for (int i = 1; i < length; ++i) {
            // 以s[i]为中心
            expandAroundCenter(s, i - 1, i + 1, indexs);
            // 以s[i - 1]、s[i]为中心
            expandAroundCenter(s, i - 1, i, indexs);
        }

        return string(s.begin() + indexs[0], s.begin() + indexs[1] + 1);
    }

private:
    // left向左扩散，right向又扩散，找到最长回文串
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

***TODO***

Manacher算法的时间复杂度为***O(n^2)***。