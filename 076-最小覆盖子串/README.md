# 076-最小覆盖子串

## 题目

leetcode：[076-最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)


## 滑动窗口

参考[438-找到字符串中所有字母异位词](./438-找到字符串中所有字母异位词/README.md)中滑动窗口的方法。在找到覆盖子串的时候，收缩滑动窗口的左边界，直到滑动窗口不再是覆盖子串为止，并在收缩的过程中记录该子串。

### unordered_map

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";

        unordered_map<char, int> m;
        for (const auto& c : t) {
            ++m[c];
        }

        int left = 0;
        int right = 0;
        int count = t.size();
        int minLenght = INT_MAX;
        while (right < s.size()) {
            if (m[s[right++]]-- >= 1) {
                --count;
            }

            while (count == 0) {
                if (minLenght > right - left) {
                    minLenght = right - left;
                    result = s.substr(left, minLenght);
                }

                if (m[s[left++]]++ >= 0) {
                    ++count;
                }
            }
        }

        return result;
    }
};
```

### 数组

使用数组比使用`unordered_map`效率高，而且在记录子串的时候，不需要每次都操作字符串，只需要记录左边界和长度即可。

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (const auto& c : t) {
            ++m[c];
        }

        int left = 0;
        int right = 0;
        int count = t.size();
        int minLeft = -1;
        int minLenght = INT_MAX;
        while (right < s.size()) {
            if (m[s[right++]]-- >= 1) {
                --count;
            }

            while (count == 0) {
                if (minLenght > right - left) {
                    minLeft = left;
                    minLenght = right - left;
                }

                if (m[s[left++]]++ >= 0) {
                    ++count;
                }
            }
        }

        return minLeft == -1 ? "" : s.substr(minLeft, minLenght);
    }
};
```

