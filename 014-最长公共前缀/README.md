# 014-最长公共前缀

## 题目

leetcode：[014-最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)


## 思路
参考[LeetCode最长公共前缀官方解答](https://leetcode-cn.com/problems/longest-common-prefix/solution/)。

## 按列扫描

1. 找出最短的字符串，设该字符串的长度为`minLength`；
2. 按列扫描，即遍历每个字符串对应索引的字符。如果不相等，则立即返回；否则，继续扫描。

时间复杂度：**O(S)**，其中`S` 为所有字符串中字符数量的总和。

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsSize = strs.size();
        if (strsSize == 0) {
            return "";
        } else if (strsSize == 1) {
            return strs[0];
        }

        int minLength = INT_MAX;
        for (const auto& str : strs) {
            minLength = min(minLength, static_cast<int>(str.size()));
        }

        for (int i = 0; i < minLength; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strsSize; ++j) {
                if (strs[j][i] != c) {
                    strs[0].substr(0, i);
                }
            }
            ++i;
        }

        return strs[0].substr(0, minLength);
    }
};
```

## 二分查找

### 二分字符串数组

对字符串数组进行二分查找最长公共前缀，最后得到的结果即为整个字符串数组的最长公共前缀。

时间复杂度：**O(S)**，其中`S` 为所有字符串中字符数量的总和。

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsSize = strs.size();
        if (strsSize == 0) {
            return "";
        } else if (strsSize == 1) {
            return strs[0];
        }

        return longestCommonPrefix(strs, 0, strsSize - 1);
    }

private:
    // 查找最长公共前缀
    string longestCommonPrefix(vector<string>& strs, int left, int right) {
        if (left == right) {
            return strs[left];
        }
        else if (left > right) {
            return "";
        }

        int mid = (left + right) / 2;
        string leftStr = longestCommonPrefix(strs, left, mid); // 查找左半边字符串的最长公共前缀
        string rightStr = longestCommonPrefix(strs, mid + 1, right); // 查找右半边字符串的最长公共前缀

        return commonPrefix(leftStr, rightStr); // 左右两部分的最长公共前缀
    }

    string commonPrefix(string& left, string& right) {
        int minSize = min(left.size(), right.size());

        for (int i = 0; i < minSize; ++i) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }

        return left.substr(0, minSize);
    }
};
```

### 二分最短字符串

1. 找出最短的字符串，设该字符串的长度为`n`。最长公共前缀的长度最大为`minLength`。
2. 使用`[0, n - 1]`中二分查找最长公共前缀。

时间复杂度：**O(S * log(n))**，其中`S` 为所有字符串中字符数量的总和。

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsSize = strs.size();
        if (strsSize == 0) {
            return "";
        } else if (strsSize == 1) {
            return strs[0];
        }

        int minLength = INT_MAX;
        for (string str : strs) {
            minLength = min(minLength, static_cast<int>(str.size()));
        }

        int low = 0;
        int high = minLength - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid + 1)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, low);

    }

private:
    // 检查字符串数组中，第一个字符串长度为 len 的前缀是不是字符串数组所有字符串的公共前缀
    bool isCommonPrefix(vector<string>& strs, int length) {
        string prefix = strs[0].substr(0, length);

        for (string str : strs) {
            if (!startWith(str, prefix)) {
                return false;
            }
        }

        return true;
    }

    // 检查字符串prefix是不是字符串str的前缀
    bool startWith(string& str, string& prefix) {
        if (str.size() < prefix.size()) {
            return false;
        }

        for (int i = 0; i < prefix.size(); ++i) {
            if (prefix[i] != str[i]) {
                return false;
            }
        }

        return true;
    }
};
```
