# 093-复原IP地址

## 题目

leetcode：[093-复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)

## 回溯法

参考[LeetCode官方题解](https://leetcode-cn.com/problems/restore-ip-addresses/solution/fu-yuan-ipdi-zhi-by-leetcode)。

因为ip的每一段只能在`0~255`之间，所以每一段只需要匹配三个位置，即该段有1、2、3个数字。

回溯的条件：

- 已经匹配了4段数字，但是字符串s还有字符为匹配；
- ip数字不能大于255；
- ip如果第一个数字为0，只能是`0`，不能是`00`、`01`、`001`。即如果第一个数字为0，那该段只能是一个字符，否则，为不合法ip。

```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) {
            return result;
        }

        dfs(s, "", 0);

        return result;
    }

private:
    vector<string> result;

    void dfs(string s, string tmpStr, int num) {
        if (num == 4) {
            if (s.empty()) {
                result.push_back(tmpStr);
            }
            return;
        }

        int len = s.size();
        for (int i = 0; i < 3 && i < len; ++i) {
            string tmp(s.begin(), s.begin() + i + 1);
            if (valid(tmp)) {
                dfs(s.substr(i + 1, len - i - 1), num == 0 ? tmp : tmpStr + "." + tmp, num + 1);
            } else {
                return;
            }
        }
    }

    bool valid(string s) {
        int len = s.size();
        if (s.empty() || len > 3 || (len > 1 && s[0] == '0')) {
            return false;
        }
        
        int n = atoi(s.c_str());
        return n <= 255 ? true : false;
    }
};
```

将临时结果字符串`tmpStr`改成引用类型，可以避免拷贝，加快运行速度。

```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) {
            return result;
        }

        dfs(s, "", 0);

        return result;
    }

private:
    vector<string> result;

    void dfs(string s, string tmpStr, int num) {
        if (num == 4) {
            if (s.empty()) {
                result.push_back(tmpStr);
            }
            return;
        }

        int len = s.size();
        if (num > 0) {
            tmpStr += ".";
        }

        for (int i = 0; i < 3 && i < len; ++i) {
            string tmp(s.begin(), s.begin() + i + 1);
            if (valid(tmp)) {
                tmpStr += tmp;
                dfs(s.substr(i + 1, len - (i + 1)), tmpStr, num + 1);
                tmpStr.erase(tmpStr.length() - (i + 1), i + 1); // 删除 tmp
            }
        }
        tmpStr.pop_back(); // 删除 “.”     
    }

    bool valid(string &s) {
        int len = s.size();
        if (s.empty() || len > 3 || (len > 1 && s[0] == '0')) {
            return false;
        }
        
        int n = atoi(s.c_str());
        return n <= 255 ? true : false;
    }
};
```

