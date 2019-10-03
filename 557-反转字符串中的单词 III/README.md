# 557-反转字符串中的单词 III

## 题目

leetcode：[557-反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

## 实现

使用两个指针，一个指向单词的第一个字母，一个指向单词的最后一个字母。依次查找单词，并将其翻转。

交换两个字母（或者数字）有三种方法：

- std::swap；
- 加减；
- 异或。

###std::swap 

```c++
class Solution {
public:
    string reverseWords(string s) {
        int length = s.size();
        for (int i = 0; i < length;) {
            int j = i + 1;
            while (j < length && s[j] != ' ') {
                ++j;
            }

            reverseWords(s, i, j - 1);

            i = j + 1;
            // 跳过空格
            while (i < length && s[i] == ' ') {
                ++i;
            }
        }

        return s;
    }

private:
    void reverseWords(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
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
    string reverseWords(string s) {
        int length = s.size();
        for (int i = 0; i < length;) {
            int j = i + 1;
            while (j < length && s[j] != ' ') {
                ++j;
            }

            reverseWords(s, i, j - 1);

            i = j + 1;
            // 跳过空格
            while (i < length && s[i] == ' ') {
                ++i;
            }
        }

        return s;
    }

private:
    void reverseWords(string& s, int start, int end) {
        while (start < end) {
            s[start] += s[end];
            s[end] = s[start] - s[end];
            s[start] = s[start] - s[end];
            ++start;
            --end;
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
    string reverseWords(string s) {
        int length = s.size();
        for (int i = 0; i < length;) {
            int j = i + 1;
            while (j < length && s[j] != ' ') {
                ++j;
            }

            reverseWords(s, i, j - 1);

            i = j + 1;
            // 跳过空格
            while (i < length && s[i] == ' ') {
                ++i;
            }
        }

        return s;
    }

private:
    void reverseWords(string& s, int start, int end) {
        while (start < end) {
            s[start] ^= s[end];
            s[end] ^= s[start];
            s[start] ^= s[end];
            ++start;
            --end;
        }
    }
};
```

