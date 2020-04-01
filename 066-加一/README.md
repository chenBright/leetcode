# 066-加一

## 题目

leetcode：[066-加一](https://leetcode-cn.com/problems/plus-one/)


## 思路

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; // 进位：0 或 1
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            digits[i] += carry;
            if (digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }

        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
```

