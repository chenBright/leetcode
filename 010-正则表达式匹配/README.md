# 010-正则表达式匹配

## 题目

leetcode：[010-正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)


## 回溯法

我一开始从字符串`s`的角度去考虑，总是不能通过所有测试。参考了[博客](https://github.com/grandyang/leetcode/issues/10)和[LeetCode官方题解](https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode)，才知道应该从字符规律`p`考虑。

### 实现1

参考[博客解法一](https://github.com/grandyang/leetcode/issues/10)的思路。

- 如果`p`为空，
  - 如果`s`为空，则返回true；
  - 否则，返回false。
- 如果`p`的长度为1，
  - 如果`s`的长度也为1，且`s[0] == p[0]`或`p[0] == '.'`，则返回true；
  - 否则，返回false。
- 如果`p`的·第二个字符不为`*`，
  - 如果`s`为空，则返回false；
  - 否则，
    - 如果`s[0] == p[0]`，则将两个字符串的第一个字符裁删除，然后递归调用函数判断两个字符串是否匹配；
    - 否则，返回false。
- 如果`p`的第二个字符为`*`，则进入循环（循环条件：`s`不为空，`s[0] == p[0]`或`p[0] == '.'`），递归调用函数（参数为`s`和删除了前两个字符的`p`）判断是否匹配。
  - 如果匹配，则返回true；
  - 否则，令`s = s.substr(0)`，继续循环。
- 如果上一步循环没有匹配而跳出循环，则还需要递归调用函数判断`s`和和删除了前两个字符的`p`是否匹配，返回结果。

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        if (p.size() == 1) {
            return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
        }

        if (p[1] != '*') {
            if (s.empty()) {
                return false;
            }

            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }

        string subP = p.substr(2);
        while (!s.empty() || (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, subP)) {
                return true;
            }
            s = s.substr(1);
        }

        return isMatch(s, subP);
    }
};
```

### 实现2

实现1存在大量的字符串拷贝，效率不高。实现2在实现1的基础上，使用引用和索引来避免拷贝。

```c++
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
private:
    bool isMatch(const string &s, int sIndex, const string &p, int pIndex) {
        int sLen = s.size();
        int pLen = p.size();
        if (pIndex == pLen) {
            return sIndex == sLen;
        }
        
        if (pIndex + 1 == pLen) {
            return sIndex + 1 == sLen && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
        }

        if (p[pIndex + 1] != '*') {
            if (sIndex == sLen) {
                return false;
            }

            return (s[sIndex] == p[pIndex] || p[pIndex] == '.') && isMatch(s, sIndex + 1, p, pIndex + 1);
        }

        for (int i = sIndex; i < sLen && (s[i] == p[pIndex] || p[pIndex] == '.'); ++i) {
            if (isMatch(s, i + 1, p, pIndex + 2)) {
                return true;
            }
        }

        return isMatch(s, sIndex, p, pIndex + 2);
    }
};
```

### 实现3

[LeetCode官方题解](https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode)给出一种更简洁的实现。

- 如果`p`为空，
  - 如果`s`为空，则返回true；
  - 否则，返回false。
- 如果`p`至少有两个字符，且第二个字符为`*`，则
  - ***匹配0个字符***：删除`p`的请两个字符，继续递归匹配；
  - 或者***匹配1个或以上字符***：前提是它能够匹配模式串当前位置字符，然后删除`s`的第一个字符，继续递归匹配。
- 否则，
  - 如果匹配模式串当前位置字符，则删除`s`和`p`的第一个字符，继续递归匹配；
  - 否咋，返回false。

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.size() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};
```

### 实现4

同实现1，实现3存在大量的字符串拷贝，效率不高。实现4在实现3的基础上，使用引用和索引来避免拷贝。

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

private:
    bool isMatch(string &s, int sIndex, string &p, int pIndex) {
        int sLen = s.size();
        int pLen = p.size();
        if (pIndex == pLen) {
            return sIndex == sLen;
        }

        bool firstMatch = sIndex < sLen && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
        if (pIndex + 1 < pLen && p[pIndex + 1] == '*') {
            return isMatch(s, sIndex, p, pIndex + 2) || (firstMatch && isMatch(s, sIndex + 1, p, pIndex));
        } else {
            return firstMatch && isMatch(s, sIndex + 1, p, pIndex + 1);
        }
    }
};
```

