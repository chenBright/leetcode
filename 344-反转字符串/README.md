# 344-反转字符串

## 题目

leetcode：[344-反转字符串](https://leetcode-cn.com/problems/reverse-string/)

## 实现

### 迭代

```c++
class Solution {
public:
    void reverseString(vector<char> &s) {
        char tmp;
        int length = s.size();
        for (int i = 0; i < length / 2; ++i) {
            swap(s[i], s[length - i - 1]);
        }
    }
};
```

### 递归

```c+
class Solution {
public:
    void reverseString(vector<char> &s) {
        reverse(s, 0, s.size() - 1);
    }
private:
    void reverse(vector<char> &s, int left, int right) {
        if (left >= right) {
            return;
        }

        swap(s[left], s[right]);
        reverse(s, left + 1, right - 1);
    }
};
```

