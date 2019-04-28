# 202-快乐数

## 题目

leetcode：[202-快乐数](https://leetcode-cn.com/problems/happy-number/comments/)

## 代码

```c++
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us = {n};
        while(true) {
            int res = 0;
            while(n > 0) {
                int temp = n % 10;
                res += temp * temp;
                n /= 10;
            }
            if(res == 1) return true;
            if(us.count(res)) return false;
            us.insert(res);
            n = res;
        }
    }
};
```

