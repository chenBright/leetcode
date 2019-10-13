# 438-找到字符串中所有字母异位词

## 题目

leetcode：[438-找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)

## 哈希表

使用哈希表记录`p`中每个字母出现的次数。遍历`s`所有子串，对比字母出现的次数是否一样。

时间复杂度：***O(mn)***，`m`表示`s`的长度，`n`表示`p`的长度。

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.empty() || p.empty() || s.size() < p.size()) {
            return result;
        }

        vector<int> m(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m[p[i] - 'a'];
        }

        for (int i = 0; i < static_cast<int>(s.size()) - static_cast<int>(p.size()) + 1; ++i) {
            vector<int> tmp(m);
            bool flag = true;
            for (int j = 0; j < p.size(); ++j) {
                char c = s[i + j];
                if (--tmp[c - 'a'] < 0) { // 该字母不存在于 p 中
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(i);
            }
        }

        return result;
    }
};
```

## 滑动窗口

[LeetCode题解](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/)总结了***滑动窗口通用思想解决“子串”问题***的方法。

### 实现1

使用两个哈希表，一个记录`p`中每个字母出现的次数，一个记录滑动窗口中字母的出现次数。如果两个哈希表相等，则表示它们是字母异位词。

时间复杂度：***O(m - n)***，`m`表示`s`的长度，`n`表示`p`的长度。

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.empty() || p.empty() || s.size() < p.size()) {
            return result;
        }

        vector<int> m1(26, 0), m2(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m1[s[i] - 'a'];
            ++m2[p[i] - 'a'];
        }
        if (m1 == m2) {
            result.push_back(0);
        }

        for (int i = 1; i < static_cast<int>(s.size()) - static_cast<int>(p.size()) + 1; ++i) {
            // 移动固定长度（p.size()）的滑动窗口
            ++m1[s[i + p.size() - 1] - 'a'];
            --m1[s[i - 1] - 'a'];

            if (m1 == m2) {
                result.push_back(i);
            }
        }

        return result;
    }
};
```

### 实现2

使用一个哈希表记录`p`中每个字母出现的次数，使用变量`count`记录还剩多少字母没有匹配，滑动窗口范围`[left, right)`。

- 移动`left`的时候，如果原`left`位置上的字母在`p`中，则需要`++count`，因为滑动窗口少了一个匹配的字母了。
- 移动`right`的时候，如果原`right`位置上的字母在`p`中，则需要`--count`，因为滑动窗口多了一个匹配的字母了。

时间复杂度：***O(m)***，`m`表示`s`的长度。

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.empty() || p.empty() || s.size() < p.size()) {
            return result;
        }

        vector<int> m(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m[p[i] - 'a'];
        }

        int left = 0;
        int right = 0;
        int count = p.size(); // 滑动窗口中已经匹配的字母数 = p.size() - count
        // 滑动窗口的范围 [left, right)
        while (right < s.size()) {
            // right 位置的字符存在于 p 中
            // 移动滑动窗口的右边界
            if (m[s[right++] - 'a']-- >= 1) {
                --count;
            }

            if (count == 0) {
                result.push_back(left);
            }

            // 窗口长度为 p.size() 且 left 位置存在于 p 中
            // 移动滑动窗口的左边界
            if (right - left == p.size() && m[s[left++] - 'a']++ >= 0) {
                ++count;
            } 
        }

        return result;
    }
};
```

