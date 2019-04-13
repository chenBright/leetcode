# 003-无重复字符的最长子串

## 题目

leetcode：[003-无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)


## 滑动窗口
参考[LeetCode 两数之和官方解答](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/)。

滑动窗口的时间复杂度为***O(n)***。

### 自己的实现

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.size();
        if (strLen <= 1) {
            return strLen;
        }        
        // 只少两个字符
        vector<int> indexs(256, -1); // 字符哈希表
        int start = 0;
        int end = 1;
        int maxLen = 1;
        indexs[s[start]] = start;

        while (start < strLen && end < strLen) {
            int index = indexs[s[end]]; // 字符索引
            // 如果字符出现过，则计算最大长度，移动滑动窗口左边界
            if (index != -1) {
                while (start <= index) {
                    indexs[s[start]] = -1;
                    ++start;
                }
            }
            maxLen = max(maxLen, end - start);
            indexs[s[end]] = end;
            // 移动滑动窗口右边界
            ++end;
        }

        // 一直遍历到字符串末尾，都没出现重复字符，则还需要计算一次最大长度
        return max(maxLen, end - start);
    }
};
```

### LeetCode参考答案

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.size();
        vector<int> indexs(256, -1); // 字符哈希表
        int start = 0;
        int end = 0;
        int maxLen = 0;

        while (start < strLen && end < strLen) {
            int index = indexs[s[end]]; // 字符索引
            // 如果字符未出现过，则扩大滑动窗口
            if (index == -1) {
                indexs[s[end]] = end;
                maxLen = max(maxLen, end - start + 1);
                // 移动滑动窗口右边界
                ++end;
            } else {
                // 移动滑动窗口左边界
                indexs[s[start++]] = -1;
            }
        }

        return maxLen;
    }
};
```

