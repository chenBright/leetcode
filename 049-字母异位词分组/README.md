# 049-字母异位词分组

## 题目

leetcode：[049-字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)

## 将单词内的字符排序

将数组中的所有单词内的字符排序，这样字母异位词排序完之后的字符串都一样。所以，可以使用排序好的字符串作为哈希表的`key`，而`value`则是该类字母异位词在结果数组中的行号。

```c++
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > result;
        if (strs.empty()) {
            return result;
        }

        // 保存单词内字符排序好的字符串
        vector<string> tmpStrs(strs);
        for (auto &str : tmpStrs) {
            sort(str.begin(), str.end());  // 排序          
        }

        unordered_map<string, int> wordMap; // 排序字符串 -> 行号
        for (int i = 0; i < tmpStrs.size(); ++i) {
            if (wordMap.count(tmpStrs[i]) != 0) { // 在 map 中存在，即表示该类字母异位词已存在记结果组中
                int row = wordMap[tmpStrs[i]];
                result[row].push_back(strs[i]);
            } else {
                result.push_back(vector<string>(1, strs[i])); // 保存一种新的字母异位词
                wordMap[tmpStrs[i]] = result.size() - 1; // 在 map 中记录行号
            }
        }

        return result;    
    }
};
```

下面的实现只需要一次循环，更简洁。相比上面的实现，需要更少的空间，但是需要的时间增加了。

```c++
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > result;
        if (strs.empty()) {
            return result;
        }


        unordered_map<string, int> wordMap;
        for (const auto &str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());  // 排序

            if (wordMap.count(tmp) != 0) { // 在 map 中存在，即表示该类字母异位词已存在记结果组中
                int row = wordMap[tmp];
                result[row].push_back(str);
            } else {
                result.push_back(vector<string>(1, str)); // 保存一种新的字母异位词
                wordMap[tmp] = result.size() - 1; // 在 map 中记录行号
            }       
        }

        return result;    
    }
};
```

## 对单词内的字符计数

参考[LeetCode官方答案](https://leetcode-cn.com/problems/group-anagrams/solution/zi-mu-yi-wei-ci-fen-zu-by-leetcode)。

```c++
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > result;
        if (strs.empty()) {
            return result;
        }

        unordered_map<string, int> wordMap;
        for (const auto &str : strs) {
            vector<int> counts(26, 0); // 记录单词中每个单词出现的频次
            for (const auto &c : str) {
                ++counts[c - 'a'];
            }
            // 将频次拼接成字符串，作为 map 的 key
            string tmp = "";
            for (const auto &n : counts) {
                tmp += "#" + to_string(n);
            }

            if (wordMap.count(tmp) != 0) { // 在 map 中存在，即表示该类字母异位词已存在记结果组中
                int row = wordMap[tmp];
                result[row].push_back(str);
            } else {
                result.push_back(vector<string>(1, str));  // 保存一种新的字母异位词
                wordMap[tmp] = result.size() - 1; // 在 map 中记录行号
            }
        }

        return result;    
    }
};
```

