# 239-滑动窗口最大值

## 题目

leetcode：[239-滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

## multiset

参考[博客解法一](https://github.com/grandyang/leetcode/issues/239)。

利用`multiset`的排序特性，不用自己管理滑动窗口内元素的顺序。因为`multiset`默认是从小到大排序的，所以每次去最后的元素，即为当前窗口的最大值。元素离开窗口的时候，则移除该元素。

时间复杂度：***O(nlog(k))***。

空间复杂度：***O(k)***。

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                s.erase(s.find(nums[i - k]));
            }
            s.insert(nums[i]);
            if (i >= k - 1) {
                result.push_back(*s.rbegin());
            }
        }

        return result;
    }
};
```

## 优先队列

参考[博客解法二](https://github.com/grandyang/leetcode/issues/239)。

该方式原理是利用堆的特性来得到最大值。其他跟使用`multiset`的方法类似。

时间复杂度：***O(nlog(k))***。

空间复杂度：***O(k)***。

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int> > q; // <nums[i], i>
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().second <= i - k) {
                q.pop();
            }

            q.push(make_pair(nums[i], i));

            if (i >= k - 1) {
                result.push_back(q.top().first);
            }
        }
        
        return result;
    }
};
```

## 双端队列

### 实现1

使用双端队列维护一个大小为`k`的队列`q`，`q[i]`表示窗口右边界元素到窗口位置`i`的最大值。当窗口滑动的时候，先删除队列头元素，再将队列内小于刚进入窗口的元素`x`的元素设置为`x`。队列头元素就是当前窗口的最大值。

时间复杂度：***O(nk)***。

空间复杂度：***O(k)***。

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
    
        deque<int> q; // q[i] 表示索引，表示窗口内 q[i] 向左到 q[i - 1] 之间的最大值

        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
```

### 实现2

优化实现1，压缩双端队列，不需要记录每个位置对应的最大值，只需要记录一段区间的最大值即可。

参考[博客解法三](https://github.com/grandyang/leetcode/issues/239)、[LeetCode官方题解中的原理解析](https://leetcode-cn.com/problems/sliding-window-maximum/solution/shi-pin-jie-xi-shuang-duan-dui-lie-hua-dong-chuang/)。

时间复杂度：***O(nk)***。

空间复杂度：***O(k)***。

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
    
        deque<int> q; // q[i] 表示索引，表示窗口内 q[i] 向左到 q[i - 1] 之间的最大值

        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
```



