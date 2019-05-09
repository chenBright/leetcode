# 056-合并区间

## 题目

leetcode：[056-合并区间](https://leetcode-cn.com/problems/merge-intervals/)

## 思路

 先将数组`intervals`的行按照第一个元素大小升序排序，使用变量`left`记录将要合并的区间的左边界，变量`right`记录将要合并的区间的左边界。遍历数组的行：

1. 如果***right < intervals\[i\]\[0\]***，则将***[left, right]***加入结果数组中，并更新`left`和`right`，其中***left = intervals\[i\]\[0\]***，***right = intervals\[i\]\[1\]***。
2. 如果***right < intervals\[i\]\[1\]***，则更新`right`，即***right = intervals\[i\]\[1\]***。

遍历结束，将最后***[left, right]***也加入结果数组中。

```c++
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        vector<vector<int> > res;
        if (intervals.empty()) {
            return res;
        }

        sort(intervals.begin(), intervals.end(), compare);

        int i = 0;
        int left = intervals[i][0];
        int right = intervals[i][1];
        vector<int> temp(2, -1);
        while (++i < intervals.size()) {
            if (right < intervals[i][0]) {
                temp[0] = left;
                temp[1] = right;
                res.push_back(temp);
                left = intervals[i][0];
                right = intervals[i][1];

            } else if (right < intervals[i][1]) {
                right = intervals[i][1];
            }
        }
        temp[0] = left;
        temp[1] = right;
        res.push_back(temp);

        return res;
    }

    static bool compare(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
};
```

