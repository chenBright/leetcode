# 091-解码方法

## 题目

leetcode：[091-解码方法](https://leetcode-cn.com/problems/decode-ways/)

## 记忆化搜索

```c++
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        unordered_map<int, int> m;

        return numDecodings(s, 0, m);
    }
private:
    int numDecodings(string& s, int i, unordered_map<int, int>& m) {
        if (m.count(i)) {
            return m[i];
        }

        int length = s.size();
        if (i == length) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        if (i + 1 == length) {
            return 1;
        }

        m[i] = numDecodings(s, i + 1, m);
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
            m[i] += numDecodings(s, i + 2, m);
        }

        return m[i];
    }
};
```

## 动态规划

解码有两个约束条件：

1. 0不能单独解码。

2. 两位数必须在`[1, 26]`区间内。

状态方程为：`f(n) = f(n - 1) + f(n - 2)`，其中

1. 如果`s[n - 1] = '0'`，则`f(n - 1) = 0，f(n) = f(n - 2)`，即前两个字母只能一起解码。

2. 如果两位数不在`[1, 26]`区间内，则`f(n) = f(n - 1)`。
3. 如果 1、2 都满足，则`f(n) = 0`。

动态规划的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        if (length == 0 || s[0] == '0') {
            return 0;
        }

        vector<int> dp(length + 1, 0);
        dp[0] = dp[1] = 1;

        // 状态方程为：f(n) = f(n - 1) + f(n - 2)，其中
        // 1. 如果 s[n - 1] = '0'，则 f(n - 1) = 0，f(n) = f(n - 2)，即前两个字母只能一起解码。
        // 2. 如果两位数不在 [1, 26] 区间内，则 f(n) = f(n - 1)。
        // 3. 如果 1、2 都满足，则 f(n) = 0。
        for (int i = 0; i < length; ++i) {
            dp[i + 1] = s[i] == '0' ? 0 : dp[i];
            if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                dp[i + 1] += dp[i - 1];
            }
        }

        return dp.back();
    }
};
```

