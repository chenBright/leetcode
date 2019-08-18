# 299-猜数字游戏

## 题目

leetcode：[299-猜数字游戏](https://leetcode-cn.com/problems/bulls-and-cows/)

## 先计算Bulls，再计算Cows

### 实现1

第一次循环（遍历`guess`数组）：

- 如果`secret[i] == guess[i]`，则`++bulls`；
- 否则，建立字符和字符在`guess`中的索引的映射。因为可能存在多个相同的字符，所以使用`stack`来保存索引。

第二次循环（遍历`guess`），如果该字符不是`Bulls`、该字符出现在`secret`中和`secret`中还有与之匹配成`Cow`的字符，则`++cows`。

```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, stack<int> > m; // 记录不是 Bulls 的索引
        int bulls = 0;
        int cows = 0;
        int len = guess.size();
        for (int i = 0; i < len; ++i) {
            char c = secret[i];
            // Bulls
            if (secret[i] == c) {
                ++bulls;
                continue;
            }

            if (m.count(c) == 0) {
                m[c] = stack<int>();
            }
            m[c].push(i);
        }

        for (int j = 0; j < len; ++j) {
            char c = guess[j];
            // 该字符是 Bull 或者 没在 secret 中出现 或者 secret 中已经没有字符与之匹配成 Cow
            if (secret[j] == c || m.count(c) == 0 || m[c].empty()) {
                continue;
            }

            // Cow
            ++cows;
            m[c].pop();
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```

### 实现2

从实现1页可以看出来，匹配为`Cow`是随便两个相同的字符即可，所以建立的映射，不需要记录所有索引，只需要记录字符出现的次数即可。

```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m; // 记录不是 Bulls 的索引
        int bulls = 0;
        int cows = 0;
        int len = guess.size();
        for (int i = 0; i < len; ++i) {
            char c = secret[i];
            // Bulls
            if (secret[i] == c) {
                ++bulls;
                continue;
            }

            if (m.count(c) == 0) {
                m[c] = 0;
            }
            ++m[c];
        }

        for (int j = 0; j < len; ++j) {
            char c = guess[j];
            // 该字符是 Bull 或者 没在 secret 中出现 或者 secret 中已经没有字符与之匹配成 Cow
            if (secret[j] == c || m.count(c) == 0 || m[c] == 0) {
                continue;
            }

            // Cow
            ++cows;
            --m[c];
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```

## 一次循环

参考[博客 解法二](https://github.com/grandyang/leetcode/issues/299)。

```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m; // 记录不是 Bulls 的索引
        int bulls = 0;
        int cows = 0;
        int len = guess.size();
        for (int i = 0; i < len; ++i) {
            // Bulls
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                // 该字符在 guess 前面（index < i）出现，
                // secret 现在才有字符与之匹配
                if (m[secret[i]]++ < 0) {
                    ++cows;
                }

                // 该字符在 secret 前面（index < i）出现，
                // guess 现在才有字符与之匹配
                if (m[guess[i]]-- > 0) {
                    ++cows;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```

