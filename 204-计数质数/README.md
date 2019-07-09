# 204-计数质数

## 题目

leetcode：[204-计数质数](https://leetcode-cn.com/problems/count-primes/)

## 蛮力法

蛮力法会超时。

```c++
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i) {
            bool flag = true;
            for (int j = 2; j <= sqrt(i); ++j) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ++count;
            }
        }

        return count;
    }
};
```

## 厄拉多塞筛法

在寻找素数时，采用了一种与众不同的方法：先将 2－N 的各数放入表中，然后在 2 的上面画一个圆圈，然后划去 2 的其他倍数；第一个既未画圈又没有被划去的数是 3，将它画圈，再划去 3 的其他倍数；现在既未画圈又没有被划去的第一个数是 5，将它画圈，并划去5的其他倍数……依次类推，一直到所有小于或等于N的各数都画了圈或划去为止。

如图所示：

![代码执行过程](/Users/chenbright/Desktop/c:c++_workspace/leetcode/204-计数质数/gif.gif)

```c++
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> primes(n, true); // 0 ~ n - 1
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                ++count;
                for (int j = 2; i * j < n; ++j) {
                    primes[i * j] = false;
                }
            }
        }

        return count;
    }
};
```

