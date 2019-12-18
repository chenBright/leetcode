# 071-简化路径

## 题目

leetcode：[071-简化路径](https://leetcode-cn.com/problems/simplify-path/)

## 思路

在我的[GitHub](https://github.com/chenBright/code_snippets/blob/master/C%2B%2B/split/README.md)总结了几种 C++ 分割字符串的方法。

```c++
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        split(path, dirs, '/');

        string result = "";
        for (const auto& d : dirs) {
            result += "/" + d;
        }

        return result.empty() ? "/" : result;
    }

private:
    void split(const std::string& str, std::vector<std::string>& tokens, const char delim = ' ') {
        std::istringstream iss(str);
        std::string tmp;
        while (std::getline(iss, tmp, delim)) {
            if (!tokens.empty() && tmp == "..") {
                tokens.pop_back();
            } else if (!tmp.empty() && tmp != "." && tmp != "..") {
                tokens.emplace_back(std::move(tmp));
            }
        }
    }
};
```

