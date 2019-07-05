# 402-移掉K位数字

## 题目

leetcode：[402-移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/)

## 贪心算法 + 单调栈

参考[博客](https://www.cnblogs.com/grandyang/p/5883736.html)。

### 实现1

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int len = num.size();
        int keep = len - k;
        for (const auto &c : num) {
            while (k != 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                --k;
            }
            result.push_back(c);
        }

        result.resize(keep);

        while (!result.empty() && result[0] == '0') {
            result.erase(result.begin());
        }

        return result.empty() ? "0" : result;
    }
};
```

### 实现2

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int len = num.size();
        int keep = len - k;
        for (const auto &c : num) {
            while (k != 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                --k;
            }
            
            // 如果 result 不为空，则无论字符是否为 '0'，都添加到 result 后面
            // 如果 result 为空，且 c 为 '0'，则不能添加到 result 后面，因为不能有前置的 '0'
            if (!result.empty() || c != '0') {
                result.push_back(c);
            }
        }

        while (!result.empty() && k != 0) {
            result.pop_back();
            --k;
        }

        return result.empty() ? "0" : result;
    }
};
```

