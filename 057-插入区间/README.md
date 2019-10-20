# 057-插入区间

## 题目

leetcode：[057-插入区间](https://leetcode-cn.com/problems/insert-interval/)

## 线性搜索

参考[博客](https://github.com/grandyang/leetcode/issues/57)。

### 实现1

遍历数组：

1. 将`intervals[current][1] < newInterval[0]`的区间加入到结果数组中，因为这部分区间肯定是在重叠区间前面。

2. `intervals[current][0] <= newInterval[1]`的区间为重叠区间，则一直更新`newInterval`：

   ```c++
   newInterval[0] = min(intervals[current][0], newInterval[0]);
   newInterval[1] = max(intervals[current][1], newInterval[1]);
   ```

   最后，将`newInterval`加入到结果数组中。

3. 将剩下的区间加入到结果数组中。

时间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > result;
        
        int current = 0;
        int length = intervals.size();
        // 将前面的区间加入结果中
        while (current < length && intervals[current][1] < newInterval[0]) {
            result.push_back(intervals[current]);
            ++current;
        }

        // 更新重叠的区间，最后加入结果中
        while (current < length && intervals[current][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[current][0], newInterval[0]);
            newInterval[1] = max(intervals[current][1], newInterval[1]);
            ++current;
        }
        result.push_back(newInterval);

        // 将后面的区间加入结果中
        while (current < length) {
            result.push_back(intervals[current]);
            ++current;
        }

        return result;
    }
};
```

### 实现2

该实现思路与实现1一样。

```c++
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > result;
        
        int index = 0; // 记录重叠区间的插入位置
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) {
                // 将前面的区间加入结果中
                result.push_back(intervals[i]);
                ++index;
            } else if (intervals[i][0] > newInterval[1]) {
                // 将前面的区间加入结果中
                result.push_back(intervals[i]);
            } else {
                // 更新重叠的区间，最后加入结果中
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }

        // 将重叠的区间插入结果中
        result.insert(result.cbegin() + index, newInterval);

        return result;
    }
};
```

## 二分查找

使用二分查找找到第一个`intervals[i][0] <= newInterval[0] <= intervals[i][1]`，即第一个重合的区间。然后遍历后面的区间，如果`newInterval[1] >= intervals[i][0]`，则更新`newInterval`。最后，插入`newInterval`，并移除重合的区间。

时间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        // 找到第一个 !comp == true 的元素，即找到第一个 intervals[i][0] <= newInterval[0] <= intervals[i][1]
        auto index = lower_bound(intervals.begin(), intervals.end(), newInterval, comp) - intervals.begin();
        
        int i = index;
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }

        intervals.insert(intervals.cbegin() + i, newInterval);
        intervals.erase(intervals.cbegin() + index, intervals.cbegin() + i);

        return intervals;
    }

private:
    static bool comp(const vector<int>& a, const vector<int>& b){
		return a[1] < b[0];
	}
};
```

