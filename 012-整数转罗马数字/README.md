# 012-整数转罗马数字

## 题目

leetcode：[012-整数转罗马数字](https://leetcode-cn.com/problems/integer-to-roman/)


## 哈希表 + 贪心算法

建立哈希表，`key`为`{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}`，`value`为`{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}`。每次从表中找尽量大的的值，找到之后，将该罗马数字添加到结果字符串，`num`减去该值后继续查找。

```c++
class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> strs{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result;
        for (int i = 0; num > 0 && i < nums.size(); ++i) {
            while (num >= nums[i]) {
                num -= nums[i];
                result += strs[i];
            }
        }

        return result;
    }
};
```

