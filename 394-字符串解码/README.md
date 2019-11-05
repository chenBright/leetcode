# 394-字符串解码

## 题目

leetcode：[394-字符串解码](https://leetcode-cn.com/problems/decode-string/)

## 栈

1. 构建辅助栈`stack`， 遍历字符串`s`中每个字符`c`；
   - 当`c`为数字时，将数字字符转化为数字`count`，用于后续倍数计算；
   - 当`c`为字母时，在`tmpStr` 尾部添加 `c`；当`c`为`[`时，将当前`count`和`tmpStr`入栈，并分别置空置 00：
   - 记录此`[`前的临时结果`tmpStr`至栈，用于发现对应`]`后的拼接操作；
     - 记录此`[`前的倍数`count`至栈，用于发现对应`]`后，获取`count × [...]`字符串。
     - 进入到新`[`后，`tmpStr`和`count`重新记录。
   - 当`c`为`]`时，`stack`出栈，拼接字符串`tmpStr = last_tmpStr + cur_count * tmpStr`，其中:
     - `last_tmpStr`是上个`[`到当前`[`的字符串，例如 "3[a2[c]]" 中的 a；
     - `cur_count`是当前`[`到`]`内字符串的重复倍数，例如 "3[a2[c]]" 中的 2。
2. 返回字符串 res。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> countStack;
    
        int count = 0;
        string tmpStr("");
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                count = count * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                countStack.push(count);
                strStack.push(tmpStr); // 当前层（[]）暂时的结果
                count = 0;
                tmpStr.clear();
            } else if (s[i] == ']') {
                int k = countStack.top();
                countStack.pop();
                for (int j = 0; j < k; ++j) {
                    strStack.top() += tmpStr;
                }
                tmpStr = strStack.top();
                strStack.pop();
            } else {
                tmpStr += s[i];
            }
        }

        return strStack.empty() ? tmpStr : strStack.top();
    }
};
```

## 递归

总体思路与辅助栈法一致，不同点在于将 [ 和 ] 分别作为递归的开启与终止条件：

- 当`s[i] == ']'`时，返回当前括号内记录的`result`字符串与`]`的索引`i`（更新上层递归指针位置）；
- 当`s[i] == '['`时，开启新一层递归，记录此`[...]`内字符串`tmp`和递归后的最新索引`i`，并执行`res + count * tmp`拼接字符串。

遍历完毕后返回`result`。


时间复杂度：***O(n)***。

空间复杂度：***O(n)***，递归栈的空间消耗。

```c++
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }

private:
    string dfs(string& s, int& i) {
        string result("");
        int length = s.size();
        while (i < length && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                result += s[i];
                ++i;
            } else {
                // 先计算次数
                int count = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    count = count * 10 + (s[i] - '0');
                    ++i;
                }

                // 递归解码
                ++i; // 跳过 "["
                string tmp = dfs(s, i);
                ++i; // 跳过 "]"

                // 拼接
                while (count-- > 0) {
                    result += tmp;
                }
            }
        }

        return result;
    }
};
```

