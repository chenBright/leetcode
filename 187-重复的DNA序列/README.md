# 187-重复的DNA序列

## 题目

leetcode：[187-重复的DNA序列](https://leetcode-cn.com/problems/repeated-dna-sequences/)

## 哈希表

### Map

遍历字符串，使用`Map`统计字符串出现的次数。最后，将出现次数超过1的字符串添加到结果数组中。

```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        vector<string> result;
        unordered_map<string, int> m;
        for (int i = 0; i + 9 < len; ++i) {
            string tmp(s.substr(i, 10));
            if (m.count(tmp)) {
                ++m[tmp];
            } else {
                m[tmp] = 1;
            }
        }

        for (const auto &item : m) {
            if (item.second > 1) {
                result.push_back(item.first);
            }
        }

        return result;
    }
};
```

### Set

使用两个`Set`，`sSet`用于保存出现过的字符串，`tmpSet`用于保存出现次数超过一次的字符串。

遍历字符串：

- 如果字符串已经在`sSet`中，则将字符串添加到`tmpSet`中。
- 否则，添加到`sSet`。

最后，将`tmpSet`中的字符串添加到结果数组中。

```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<string> sSet;
        unordered_set<string> tmpSet;
        for (int i = 0; i + 9 < len; ++i) {
            string tmp(s.substr(i, 10));
            if (sSet.count(tmp)) {
                tmpSet.insert(tmp);
            } else {
                sSet.insert(tmp);
            }
        }

        return vector<string>(tmpSet.begin(), tmpSet.end());
    }
};
```

## 哈希表 + 位运算

使用位运算可以减少内存使用，并加快运算速度。

参考[博客](https://www.cnblogs.com/grandyang/p/4284205.html)。

### 每个字母用3个位表示

```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<int> bitSet;
        unordered_set<string> tmpSet;


        // A, C, G, T 的 ASCII 码用二进制来表示：
        // A: 0100 0001　　C: 0100 0011　　G: 0100 0111　　T: 0101 0100
        // 只需取后 3 位就能唯一表示这些字母
        int current = 0;
        for (int i = 0; i < 9; ++i) {
            // 拼接 位
            current = (current << 3) | (s[i] & 7);
        }

        // 滑动窗口
        for (int j = 9; j < len; ++j) {
            // 将当前字符的 位 添加到后面
            // 用 mask = 0x7ffffff 取出后 27 位，在向左移动 3 位，
            // 最后拼接下一个字母的 位
            current = ((current & 0x7ffffff) << 3) | (s[j] & 7);
            if (bitSet.count(current)) {
                tmpSet.insert(s.substr(j - 9, 10));
            } else {
                bitSet.insert(current);
            }
        }

        return vector<string>(tmpSet.begin(), tmpSet.end());
    }
};
```

### 每个字母用2个位表示

```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<int> bitSet;
        unordered_set<string> tmpSet;

        // A: 00　　C: 01　　G: 10　　T: 11
        // 只需取后 2 位就能唯一表示这些字母
        unordered_map<char, int>m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

        int current = 0;
        for (int i = 0; i < 9; ++i) {
            // 拼接 位
            current = (current << 2) | (m[s[i]]);
        }

        // 滑动窗口
        for (int j = 9; j < len; ++j) {
            // 将当前字符的 位 添加到后面
            // 用 mask = 0x3fffff 取出后 18 位，在向左移动 2 位，
            // 最后拼接下一个字母的 位
            current = ((current & 0x3ffff) << 2) | (m[s[j]]);
            if (bitSet.count(current)) {
                tmpSet.insert(s.substr(j - 9, 10));
            } else {
                bitSet.insert(current);
            }
        }

        return vector<string>(tmpSet.begin(), tmpSet.end());
    }
};
```

### bitset

[LeetCode评论区](https://leetcode-cn.com/problems/repeated-dna-sequences/comments/106831)使用`bitset`来表示位的实现。