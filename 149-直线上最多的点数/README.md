# 149-直线上最多的点数

## 题目

leetcode：[149-直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/)

## 蛮力法

时间复杂度：***O(n^3)***。

```c++
class Solution {
public:
    int maxPoints(vector<vector<int> > &points) {
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1; // ??????
            for (int j = i + 1; j < points.size(); ++j) {
                int count = 0;
                long long x1 = points[i][0];
                long long y1 = points[i][1];
                long long x2 = points[j][0];
                long long y2 = points[j][1];
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++count;
                    }
                }
                result = max(result, count);
            }
            result = max(result, duplicate);
        }
        return result;
    }
};
```

## map

时间复杂度：***O(n^2)***。

```c++
class Solution {
public:
    int maxPoints(vector<vector<int> > &points) {
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m; // <<除数 / 最大公约数, 被除数 / 最大公约数>, 点的个数>
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcb(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            result = max(result, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                result = max(result, it->second + duplicate);
            }

        }
        return result;
    }

private:
    // 计算最大公约数
    int gcb(int a, int b) {
        return b == 0 ? a : gcb(b, a % b);
    }
};
```

