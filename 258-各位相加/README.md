# 258-各位相加

## 题目

leetcode：[258-各位相加](https://leetcode-cn.com/problems/add-digits/)

## 模拟题目的计算方法

### 递归

```c++
class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        int newNum = 0;
        while (num != 0) {
            newNum += num % 10;
            num /= 10;
        }

        return addDigits(newNum);
    }
};
```

### 迭代1

```c++
class Solution {
public:
    int addDigits(int num) {
        stack<int> tmp;
        while (num != 0) {
            tmp.push(num % 10);
            num /= 10;
        }

        int result = 0;
        while (!tmp.empty()) {
            result += tmp.top();
            tmp.pop();
            // 如果 result 大于等于 10，则将十位压回栈中，留下个位
            if (result >= 10) {
                tmp.push(result / 10);
                result %= 10;
            }
        }

        return result;
    }
};
```

### 迭代2

```c++
class Solution {
public:
    int addDigits(int num) {
        while (num / 10 != 0) { // num 不是个位数
            int sum = 0;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }

        return num;
    }
};
```

## 数学

参考[LeetCode题解](https://leetcode-cn.com/problems/add-digits/solution/java-o1jie-fa-de-ge-ren-li-jie-by-liveforexperienc)。

时间复杂度：***O(1)***。

```c++
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
```

