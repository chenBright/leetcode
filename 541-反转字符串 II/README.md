# 541-反转字符串 II

## 题目

leetcode：[541-反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

## 实现

使用两个指针，一个指向单词的第一个字母，一个指向单词的最后一个字母。依次查找单词，并将其翻转。

交换两个字母（或者数字）有三种方法：

- std::swap；
- 加减；
- 异或。

### std::swap

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        for (int i = 0; i < length; i += 2 * k) {
            int left = i;
            int right = min(length - 1, i + k - 1);
            reverseStr(s, left, right);
        }

        return s;
    }

private:
    void reverseStr(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};
```

### 加减

交换`a`和`b`，可以这样：

```
a = a + b
b = a - b
a = a - b
```

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        for (int i = 0; i < length; i += 2 * k) {
            int left = i;
            int right = min(length - 1, i + k - 1);
            reverseStr(s, left, right);
        }

        return s;
    }

private:
    void reverseStr(string& s, int left, int right) {
        while (left < right) {
            s[left] += s[right];
            s[right] = s[left] - s[right];
            s[left] = s[left] - s[right];
            ++left;
            --right;
        }
    }
};
```

### 异或

交换`a`和`b`，可以这样：

```
a ^= b
b ^= a
a ^= b
```

使用到的性质：`a ^ a = 0`、`a ^ a ^ b = b`。

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        for (int i = 0; i < length; i += 2 * k) {
            int left = i;
            int right = min(length - 1, i + k - 1);
            reverseStr(s, left, right);
        }

        return s;
    }

private:
    void reverseStr(string& s, int left, int right) {
        while (left < right) {
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            ++left;
            --right;
        }
    }
};

```

