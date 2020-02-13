# 567-字符串的排列

## 题目

leetcode：[567-字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

## 滑动窗口

### 实现1

参考[438-找到字符串中所有字母异位词 滑动窗口实现2](../438-找到字符串中所有字母异位词/README.md#实现2)。

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();
        
        unordered_map<char, int> m;
        for (const auto& c : s1) {
            ++m[c];
        }

        int left = 0;
        int right = 0;
        int count = length1;
        while (right < length2) {
            if (m[s2[right++]]-- > 0) {
                --count;
            }

            if (count == 0) {
                return true;
            }

            if (right - left == length1 && ++m[s2[left++]] > 0) {
                ++count;
            }
        }

        return false;
    }
};
```

### 实现2

将实现1的`unordered_map`替换成数组。

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();
        
        vector<int> m(26, 0);
        for (const auto& c : s1) {
            ++m[c - 'a'];
        }

        int left = 0;
        int right = 0;
        int count = length1;
        while (right < length2) {
            if (--m[s2[right++] - 'a'] >= 0) {
                --count;
            }

            if (count == 0) {
                return true;
            }

            if (right - left == length1 && ++m[s2[left++] - 'a'] > 0) {
                ++count;
            }
        }

        return false;
    }
};
```

### 实现3

参考[438-找到字符串中所有字母异位词 滑动窗口实现1](../438-找到字符串中所有字母异位词/README.md#实现1)。

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();

        if (length1 > length2) {
            return false;
        }

        vector<int> m1(26, 0); // 记录 s1 中字母的个数
        vector<int> m2(26, 0); // 记录 s2 上滑动窗口内字母的个数

        for (int i = 0; i < length1; ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }

        if (m1 == m2) {
            return true;
        }

        for (int j = length1; j < length2; ++j) {
            // 移动滑动窗口，大小 = length1
            ++m2[s2[j] - 'a'];
            --m2[s2[j - length1] - 'a'];

            if (m1 == m2) {
                return true;
            }
        }

        return false;
    }
};
```

### 实现4

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();

        vector<int> m(26, 0);
        for (const auto& c : s1) {
            ++m[c - 'a'];
        }

        int left = 0;
        int right = 0;
        // 滑动窗口：[left, right]
        while (right < length2) {
            if (--m[s2[right] - 'a'] < 0) {
                // 收缩 left，++m[s2[i] - 'a']
                // ++m[s2[i] - 'a'] < 0，表示该字符不是字符串的排列
                // 或者 i 后面已经出现该字符了，即该字符是多出来的
                while (++m[s2[left++] - 'a'] > 0);
            } else if (right - left + 1 == length1) {
                return true;
            }
            ++right;
        }

        return false;
    }
};
```

