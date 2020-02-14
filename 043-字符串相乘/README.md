# 043-字符串相乘

## 题目

leetcode：[043-字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)

## 模拟乘法

需要注意的是：字符串存储数字的方式是大端模式，即最高位从0开始。则乘法的规律为**`nums1`的第i位与`nums2`的第j位相乘，其结果在最终乘积结果的第[i + j, i + j + 1]上**。例如: `123 * 45`,  `123`的第 1 位的`2`和`45`的第0 位`4`乘积“08”存放在结果的第[1, 2]位上。

```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") {
            return "0";
        }

        int length1 = num1.size();
        int length2 = num2.size();
        string result(length1 + length2, '0');
        for (int i = length1 - 1; i >= 0; --i) {
            for (int j = length2 - 1; j >= 0; --j) {
                // 两数相乘，再加上原低位数值
                int tmp = charToInt(num1[i]) * charToInt(num2[j]) + charToInt(result[i + j + 1]);
                result[i + j] += tmp / 10;
                result[i + j + 1] = tmp % 10 + '0'; // + '0'，将低位转成字符
            }
        }

        auto index = result.find_first_not_of('0'); // 查找第一个不是'0'的元素的位置

        return index != string::npos ? result.substr(index) : "0";
    }

private:
    inline int charToInt(const char c) {
        return c - '0';
    }
};
```

