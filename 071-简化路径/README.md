# 071-简化路径

## 题目

leetcode：[071-简化路径](https://leetcode-cn.com/problems/simplify-path/)


## 思路

```c++
class Solution {
public:
    string simplifyPath(string path) {
        int length = path.size();
        if (length == 0) {
            return "/";
        }

        vector<string> dirs;
        int i = 0;
        // 分割字符串，分割字符是“/”
        while (i < length) {
            if (path[i] == '/') {
                ++i;
                continue;
            } else {
                string str(1, path[i]);
                int j = i + 1;
                while (j < length && path[j] != '/') {
                    str += path[j];
                    ++j;
                }
                dirs.push_back(str);
                i = j;
            }
        }

        // 处理文件夹
        stack<string> readDirs;
        for (const auto &dir : dirs) {
            if (dir == ".") {
                continue;
            } else if (dir != "..") {
                readDirs.push(dir);
            } else {
                if (!readDirs.empty()) {
                    readDirs.pop();
                }
            }
        }

        // 拼接路径字符串
        string res = "";
        while (!readDirs.empty()) {
            res = "/" + readDirs.top() + res;
            readDirs.pop();            
        }

        return res.empty() ? "/" : res;
    }
};
```

