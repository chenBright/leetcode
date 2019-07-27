# 223-矩形面积

## 题目

leetcode：[223-矩形面积](https://leetcode-cn.com/problems/rectangle-area/)

## 思路

该题关键为计算重叠区域的面积，然后`所求面积 = 矩形1面积 + 矩形2面积 - 重叠区域面积`。

参考[博客](https://www.cnblogs.com/grandyang/p/4563153.html)。

### 实现1

```c++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);

        if (F >= D || E >= C || H <= B || G <= A) {
            return area1 + area2;
        }

        return area1 + area2 - (min(C, G) - max(E, A)) * (min(D, H) - max(B, F));
    }
};
```

### 实现2

```c++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int right = max(min(C, G), left);
        int bottom = max(B, F);
        int top = max(min(D,H), bottom);

        return (C - A) * (D - B) - (right - left) * (top - bottom) + (G - E) * (H - F);
    }
};
```

