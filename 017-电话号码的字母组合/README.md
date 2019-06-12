# 017-电话号码的字母组合

## 题目

leetcode：[017-电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)


## DFS

```c++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        unordered_map<char, string> table{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},{'8', "tuv"}, {'9', "wxyz"}
        };

        combinate(digits, 0, "", table, result);

        return result;

    }

private:
    void combinate(string &digits, int index, string str,
                   unordered_map<char, string> &table, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(str);
            return;
        }

        string chars = table[digits[index]];
        for (const auto &c : chars) {
            str += c;
            combinate(digits, index + 1, str, table, result);
            str.pop_back();
        }
    }
};
```

## BFS

```c++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        unordered_map<char, string> table{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},{'8', "tuv"}, {'9', "wxyz"}
        };

        result.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> tmp;
            string chars = table[digits[i]];
            for (const auto &lastStr : result) {
                for (const auto &c : chars) {
                    tmp.push_back(lastStr + c);
                }
            }
            result = tmp;
        }

        return result;
    }
};
```