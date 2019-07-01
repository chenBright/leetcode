# 134-加油站

## 题目

leetcode：[134-加油站](https://leetcode-cn.com/problems/gas-station/)

## 贪心算法

贪心算法的时间复杂度为***O(n)***。

### 实现1

参考[LeetCode官方题解](https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode)。

```c++
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int toatalTank = 0; // 总油量
        int currentTank = 0; // 当前油量
        int index = 0; // 起点
        for (int i = 0; i < gas.size(); ++i) {
            int remain = gas[i] - cost[i];
            toatalTank += remain;
            currentTank += remain;
            if (currentTank < 0) {
                index = i + 1;
                currentTank = 0;
            }
        }

        return toatalTank < 0 ? -1 : index;
    }
};
```

### 实现2

参考[博客 解法二](https://www.cnblogs.com/grandyang/p/4266812.html)。

```c++
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int toatalTank = 0; // 总油量
        int maxTank = 0; // 剩余油量的最大值
        int index = 0; // 起点
        for (int i = gas.size() - 1; i >= 0; --i) {
            toatalTank += gas[i] - cost[i];
            if (toatalTank > maxTank) {
                index = i;
                maxTank = toatalTank;
            }
        }

        return toatalTank < 0 ? -1 : index;
    }
};
```

