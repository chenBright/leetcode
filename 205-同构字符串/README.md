# 205-同构字符串

## 题目

leetcode：[205-同构字符串](https://leetcode-cn.com/problems/isomorphic-strings/)

## 使用哈希表记录替换字符

使用两个哈希表，一个哈希表记录`s[i]`到`t[i]`的映射，一个哈希表记录`t[i]`到`s[i]`的映射。

- 如果两个哈希表都没有对应的映射时，则建立对应映射；
- 如果两个哈希表都建立了映射，但并不匹配，即哈希表中的`value`不等于`s[i]`或`t[i]`，则返回false；
- 如果有且只有一个哈希表建立了映射，则返回false。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> mS2T;
        unordered_map<char, char> mT2S;
        for (int i = 0; i < s.size(); ++i) {
            if (mS2T.find(s[i]) == mS2T.end() && mT2S.find(t[i]) == mT2S.end()) { // 没有替换过
                mS2T[s[i]] = t[i];
                mT2S[t[i]] = s[i];
            } else if (mS2T.find(s[i]) != mS2T.end() && mT2S.find(t[i]) != mT2S.end()) {
                if (mS2T[s[i]] != t[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};
```

## 使用哈希表记录替换字符的索引

该方法中，哈希表记录的不是替换字符，而是他们在字符串中的位置。

该方法的时间复杂度为***O(n)***。

### unordered_map

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> mS2T;
        unordered_map<char, int> mT2S;
        for (int i = 0; i < s.size(); ++i) {
            if (mS2T.find(s[i]) == mS2T.end() && mT2S.find(t[i]) == mT2S.end()) {
                mS2T[s[i]] = i;
                mT2S[t[i]] = i;
            } else if (mS2T.find(s[i]) != mS2T.end() && mT2S.find(t[i]) != mT2S.end()) {
                if (mS2T[s[i]] != mT2S[t[i]]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return true;
    }
};
```

### 数组

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int mS2T[256] = {0};
        int mT2S[256] = {0};
        for (int i = 0; i < s.size(); ++i) {
            if (mS2T[s[i]] != mT2S[t[i]]) {
                return false;
            }

            mS2T[s[i]] = i + 1; // 因为数组默认值为 0，代表没有替换
            mT2S[t[i]] = i + 1;
        }
        
        return true;
    }
};
```

## 不需要哈希表

每次替换，查找两个字符串中遍历到的字符在其所在字符串中第一次出现的位置，如果两个位置不相等，则表示不匹配，返回false。

该方法的时间复杂度为***O(n^2)***。

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (s.find(s[i]) != t.find(t[i])) {
                return false;
            }
        }
        
        return true;
    }
};
```

