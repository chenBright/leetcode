# 022-括号生成

## 题目

leetcode：[022-括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

参考[LeetCode 官方题解](https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode)。

## 回溯法

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) {
            return result;
        }

        generate("", 0, 0, n, result);

        return result;
    }

private:
    void generate(string str, int left, int right, int n, vector<string> &result) {
        if (left + right == 2 * n) {
            result.push_back(str);
            return;
        }

        // 只要左括号没够 n 个，都可以添加到左括号
        if (left < n) {
            generate(str + "(", left + 1, right, n, result);
        }

        // 只有左括号数大于右括号数，才可以添加到右括号；
        // 不然，会生成不合法字符，即右括号与左括号不匹配
        if (left > right) {
            generate(str + ")", left, right + 1, n, result);
        }

    }
};
```

## 闭合数

按照我的理解，这里生成的括号有某种“对称性”。

### 官方实现

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) {
            result.push_back("");
        } else {
            for (int i = 0; i < n; ++i) {
                for (const auto &left : generateParenthesis(i)) { // 存在重复计算
                    for (const auto &right : generateParenthesis(n - 1 - i)) { // 存在重复计算
                        result.push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return result;
    }
};
```

### 保存中间就算结果，减少重复计算

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) {
            result.push_back("");
        } else {
            for (int i = 0; i < n; ++i) {
                vector<string> lefts;
                if (results.count(i)) {
                    lefts = results[i];
                } else {
                    lefts = generateParenthesis(i);
                    results[i] = lefts;
                }

                for (const auto &left : lefts) {
                    vector<string> rights;
                    int tmp = n - 1 - i;
                    if (results.count(tmp)) {
                        rights = results[tmp];
                    } else {
                        rights = generateParenthesis(tmp);
                        results[tmp] = rights;
                    }

                    for (const auto &right : rights) {
                        result.push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return result;
    }

private:
    unordered_map<int, vector<string> > results;
};
```