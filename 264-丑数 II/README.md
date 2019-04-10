# 264-丑数 II

## 题目

leetcode：[264-丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)

## 蛮力法

递归实现效率不高，在LeetCode上会"超出时间限制"。

蛮力法的时间复杂度为***O(n^2)***。

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return -1;
        }

        int num = 0;
        int count = 1;
        while (count <= n) {
            ++num;
            if (isUglyNumber(num)) {
                ++count;
            }
        }

        return num;
    }

private:
    // 判断n是不是丑数
    bool isUglyNumber(int n) {
        if (n <= 0) {
            return false;
        }

        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 5 == 0) {
                n /= 5;
            } else {
                return false;
            }
        }

        return true;
    }
};
```

## 三指针（动态规划）

使用***数组uglyNumbers***保存丑数，后面的丑数可以用前面的丑数乘以2、3或5得到。使用三个指针分别指向要乘以2、3、5的数字，每次取出最小值，并将对应指针向后移动一位。

动态规划的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);

        int indexOf2 = 0; // 指向要乘2的数
        int indexOf3 = 0; // 指向要乘3的数
        int indexOf5 = 0; // 指向要乘5的数

        while (uglyNumbers.size() <= n) {
            int num = min(uglyNumbers[indexOf2] * 2, uglyNumbers[indexOf3] * 3, uglyNumbers[indexOf5] * 5);
            uglyNumbers.push_back(num);

            // 将产生这个丑数的index*向后挪一位
            // 用三个独立的if判断，因为可能有两个最小值，这时都要挪动
            if (num == uglyNumbers[indexOf2] * 2) {
                ++indexOf2;
            } 
            if (num == uglyNumbers[indexOf3] * 3) {
                ++indexOf3;
            } 
            if (num == uglyNumbers[indexOf5] * 5) {
                ++indexOf5;
            }
        }

        return uglyNumbers[n - 1];
    }

private:
    int min(int a, int b, int c) {
        int min = a < b ? a : b;
        if (c < min) {
            min = c;
        }

        return min;
    }
};
```

