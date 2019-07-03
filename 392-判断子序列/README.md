# 392-判断子序列

## 题目

leetcode：[392-判断子序列](https://leetcode-cn.com/problems/is-subsequence/)

## 贪心算法 + 双指针

使用一个指针`i`指向字符串`s`，另一个指针`j`指向字符串`t`。

遍历`t`：

- 如果`s[i] == t[j]`，则`++i;++j`；
- 否则，只需要`++j`。

```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // 指向 s
        int j = 0; // 指向 t
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }

        return i == s.size();
    }
};
```

## 后续挑战

该问题的关键在于需要判断大量输入的S是否为t的子序列。因为t是不变的，所以每一次判断`Si`时都遍历t的话，效率不高。使用哈希表保存t中每个字符的索引值，这样就不需要遍历t，只需要遍历`Si`即可。每次遍历到的字符c，在哈希表中找是否存在该字符。

因为t中的同一个字符科能出现多次，所以需要使用数组来保存这些索引值。还需要使用一个变量`preIndex`记录上一个字符在t中的索引值。在哈希表中查找索引值时，使用`lower_bound`查找第一个大于等于`preIndex`的值。

- 当迭代器等于`end()`时，表示不是子序列，则检查下一个字符串。
- 当迭代器不等于`end()`时，如果查找的值等于`preIndex`，还需要向后移动迭代器。再次判断迭代器是都等于`end()`。
  - 如果相等，表示不是子序列，则检查下一个字符串。
  - 如果不相等，则令`preIndex`等于查找到的值，继续检查下一个字符。

```c++
class Solution {
public:
    vector<bool> isSubsequence(vector<string> strs, string t) {
        if (t.empty()) {
            return vector<bool>(strs.size(), false);
        }

        unordered_map<char, vector<int> > m;
        for (int i = 0; i < t.size(); ++i) {
            m[t[i]].push_back(i);
        }

        vector<bool> result(strs.size(), true);
        for (int j = 0; j < strs.size(); ++j) {
            string s = strs[j];
            int preIndex = 0;
            for (int k = 0; k < s.size(); ++k) {
                vector<int> v = m[s[k]];
                // 查找第一个大于等于 preIndex 的值
                auto it = lower_bound(v.begin(), v.end(), preIndex);
                if (it == v.end()) { // 没有找到，则不是子序列
                    result[j] = false;
                    break;
                }
                // 如果 *it == preIndex，表示 s[k] == s[k - 1]，
                // 则迭代器需要指向下一个值，该值才是 s[k] 对应的索引值
                if (*it == preIndex) {
                    ++it;
                    if (it == v.end()) {
                        result[j] = false;
                        break;
                    }
                }
                preIndex = *it;
            }
        }

        return result;
    }
};
```

