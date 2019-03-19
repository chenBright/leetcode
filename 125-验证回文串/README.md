# 125-验证回文串

## 题目

leetcode：[125-验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)

## 思路

使用双指针，一个指针从字符串前向后遍历，一个指针从字符串后向前遍历，比较两指针指向的字符是否相同。遍历的时候，如果遇到非数字或者字符，则跳过。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        int left = 0;
        int right = 0;
        while ( left < right) {
            if (!isAlphanum(s[left])) { // 跳过
                ++left;
            } else if (!isAlphanum(s[right])) { // 跳过
                --right;
            } else if (tolower(s[left]) != tolower(s[right])) { // 字符不相同
                return false;
            } else { // 字符相同，则继续遍历
                ++left;
                --right;
            }
        }

        return true;
    }

private:
    // 是否为数字或者字母
    bool isAlphanum(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
};
```

