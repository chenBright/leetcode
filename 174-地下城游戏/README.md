# 174-地下城游戏

## 题目

leetcode：[174-地下城游戏](https://leetcode-cn.com/problems/dungeon-game/)

## 深度优先搜索

每到一个位置，如果`memory`记录了当前位置到终点的最少健康值，则直接返回。如果没有，则从向右或者向下路径中找出消耗最少的路径，比加上当前位置的值。

- 如果结果大于0，则返回0，表示后面的路径不需要消耗健康值。
- 如果结果小于0，则直接返回。

同时，在返回值之前，将值记录到`memory`中。

最后，将值取反再加1。因为得到的值为负数，并且健康值不能降为0，最小为1。

```c++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if (dungeon.empty()) {
            return 0;
        }

        int row = dungeon.size();
        int col = dungeon[0].size();
        // memory[i][j] 记录 从 dungeon[i][j] 到终点至少需要多少健康值
        vector<vector<int> > memory(row, vector<int>(col, INT_MIN));

        // 健康值不能降为 0，所以还要 - 1
        return -dfs(dungeon, 0, 0, memory) + 1;
        
    }
private:
    int dfs(vector<vector<int> >& dungeon, int rowIndex, int colIndex, vector<vector<int> >& memory) {
        if (rowIndex == dungeon.size() - 1 && colIndex == dungeon[0].size() - 1) {
            return min(dungeon[rowIndex][colIndex], 0);
        }

        if (memory[rowIndex][colIndex] != INT_MIN) {
            return memory[rowIndex][colIndex];
        }

        int result = 0;
        if (rowIndex == dungeon.size() - 1) { // 最后一行
            result = min(dungeon[rowIndex][colIndex] + dfs(dungeon, rowIndex, colIndex + 1, memory), 0);
        } else if (colIndex == dungeon[0].size() - 1) { // 最后一列
            result = min(dungeon[rowIndex][colIndex] + dfs(dungeon, rowIndex + 1, colIndex, memory), 0);
        } else {
            result = max(dfs(dungeon, rowIndex + 1, colIndex, memory), dfs(dungeon, rowIndex, colIndex + 1, memory)); // 展出消耗少的路径
            result = min(dungeon[rowIndex][colIndex] + result, 0);
        }

        memory[rowIndex][colIndex] = result;

        return result;
    }
};
```

## 动态规划

参考[博客](https://github.com/grandyang/leetcode/issues/174)。

受`深度优先搜索`的方法启示，可以看成，需要从终点到起点进行动态规划，动态规划得到的表示当前位置到终点需要消耗的健康值。从起点到终点进行动态规划并不能解决这道题。例如下面两个路径：

| -2   | -3   | 3    |
| ---- | ---- | ---- |
| -5   | -10  | 1    |
| 10   | 30   | -5   |



```
-2 -> -3 -> 3 -> 1 -> -5
-2 -> -5 -> 10 -> 30 ->-5
```

明显，路径1至少需要的健康值为7，而路径2至少需要的健康值为8。

即使路径的值加起来的值，路径2更大。路径2前面需要消耗7健康值，即使后面后补充10 + 30，也没办法使得前面消耗的健康值减小，可以理解为沉没成本。换句话说，当前的值只对路径后面部分产生影响。

### 二维数组

使用二维数组`dp`记录消耗的健康值，`dp[i][j]`表示从`dungeon[i][j]`到终点至少需要多少健康值。

时间复杂度：***O(n\*m)***。

空间复杂度：***O(n\*m)***。

其中，`n`为行数，`m`为列数。

```c++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if (dungeon.empty()) {
            return 0;
        }

        int row = dungeon.size();
        int col = dungeon[0].size();
        // dp[i][j] 表示从 dungeon[i][j] 到终点至少需要多少健康值。
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, INT_MIN));
        dp[row - 1][col] = 0;
        dp[row][col - 1] = 0;

        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                int minPath = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = min(minPath + dungeon[i][j], 0);
            }
        }

        // 健康值不能降为 0，所以还要 - 1
        return -dp[0][0] + 1;
    }
};
```

### 一维数组

根据前面的方法，对空间进行优化，将二维数组压缩为一维数组。

时间复杂度：***O(n\*m)***。

空间复杂度：***O(m)***。

其中，`n`为行数，`m`为列数。

```c++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if (dungeon.empty()) {
            return 0;
        }

        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<int> dp(col + 1, INT_MIN);
        // dp[col] = INT_MIN，表示永远不会选择会越界的路径
        dp[col - 1] = 0;

        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                int minPath = max(dp[j], dp[j + 1]);
                dp[j] = min(minPath + dungeon[i][j], 0);
            }
        }

        // 健康值不能降为 0，所以还要 - 1
        return -dp[0] + 1;
    }
};
```

