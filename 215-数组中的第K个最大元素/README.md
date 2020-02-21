# 215-数组中的第K个最大元素

## 题目

leetcode：[215-数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

## 排序

### 对所有元素排序

先排序，然后找出前k小的数字即可。

该方法的时间复杂度为**O(nlogn)**。

```c++
bool cmp(int a, int b) {
        return a > b;
}

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        sort(nums.begin(), nums.end(), cmp); // 从大到小排序

        return nums[k - 1];
    }
};
```

题目只需要前k小的数字，所以不需要对所有元素进行排序。有一些排序算法每一次循环可以确定一个”最值“，可以让排序算法的外循环运行k次即可。

### 选择排序

```c++
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        for (int i = 0; i < k; ++i) {
            int max = i;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[max]) {
                    max = j;
                }
            }

            if (max != i) {
                swap(nums[max], nums[i]);
            }
        }

        return nums[k - 1];
    }
};
```

### 冒泡排序

```c++
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        for (int i = 0; i < k; ++i) {
            for (int j = nums.size() - 1; j > i; --j) {
                if (nums[j] > nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }

        return nums[k - 1];
    }
};
```

以上两个排序算法的实现的时间复杂度为**O(nk)**。

## 基于Partition函数的查找第K大的数

使用快排中的`partition`函数修改数组，使得第 k 个数字左边的数字都比第 k 个数字大，右边的数字都比第 k 个数字小，则第 k 个数字即为所求。

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k == 0 || k > nums.size()) {
            return -1;
        }

        return findKth(nums, 0, nums.size() - 1, k - 1);
    }

private:
    int findKth(vector<int>& nums, int low, int high, int kIndex) {
        int index = partition(nums, low, high);
        if (index == kIndex) {
            return nums[kIndex];
        } else if (index < kIndex) {
            return findKth(nums, index + 1, high, kIndex);
        } else {
            return findKth(nums, low, index - 1, kIndex);
        }
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivotNum = nums[low];  // 基准元素

        while (low < high) {
            // 从后面开始找，找到第一个不小于基准元素的元素
            while (low < high && nums[high] < pivotNum) {
                --high;
            }
            if (low == high) {
                break;
            }
            nums[low] = nums[high];
            ++low;

            // 从前面开始找，找到第一个小于基准元素的元素
            while (low < high && nums[low] >= pivotNum) {
                ++low;
            }
            if (low == high) {
                break;
            }
            nums[high] = nums[low];
            --high;
        }
        nums[low] = pivotNum;

        return low;
    }
};
```

## 大堆

利用所有元素构建一个大堆，然后取堆中的前k个数。

该方法的时间复杂度为***O(n+k*logn)**。

```c++
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        make_heap(nums.begin(), nums.end(), less<int>());  // 构造最大堆
        for (int i  = 0; i < k - 1; ++i) {
            pop_heap(nums.begin(), nums.end(), less<int>());
            nums.pop_back();
        }

        return nums[0];
    }
};
```

## 优先队列

在c++中优先队列是用堆现实的，所以**大堆**的思路一样。当然，时间复杂度也是**O(n+k*logn)**。

```c++
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        priority_queue<int, vector<int>, less<int> > pq(nums.begin(), nums.end());

        // 将钱 k - 1 个数出队列
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }

        return pq.top();
    }
};
```

## 小堆

对于前面**大堆**的方法，没有必要构建容量为`n`的堆，只需要构建一个容量为`k`的小堆。使用剩下的`n-k`个元素与堆顶元素比较：

- 如果元素比堆顶元素大，则删除堆顶元素，然后插入该元素。

- 否则，不更新大堆。

时间复杂度为**O(k+(n-k)*logk) = O(nlogk)**。

### 优先队列实现

优先队列的底层结构是堆。

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if (nums.empty() || k == 0 || k > length) {
            return -1;
        }

        // 构建容量为 k 的最小堆
        priority_queue<int, vector<int>, greater<int> > q(nums.begin(), nums.begin() + k);

        for (int i = k; i < length; ++i) {
            if (nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }

        return q.top();
    }
};
```
### 堆函数

使用 STL 中的对函数：`make_heap`。

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if (nums.empty() || k == 0 || k > length) {
            return -1;
        }

        make_heap(nums.begin(), nums.begin() + k, greater<int>());

        for (int i = k; i < length; ++i) {
            if (nums[i] > nums[0]) {
                swap(nums[i], nums[0]);
                make_heap(nums.begin(), nums.begin() + k, greater<int>());
            }
        }

        return nums[0];
    }
};
```

## 红黑树

使用**红黑树**也可以实现**小堆**的思路。`multiset`的底层数据结构是红黑树。

```c++
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int length = nums.size();
        if (nums.empty() || k == 0 || k > length) {
            return -1;
        }

        // 构造含有 k 个元素红黑树（小堆）
        multiset<int, less<int> > maxSet(nums.begin(), nums.begin() + k);

        for (int i = k; i < length; ++i) {
            auto it = maxSet.begin();
            // 如果元素比堆顶元素大，则删除堆顶元素，然后插入该元素。
            if (nums[i] > *it) {
                maxSet.erase(it);
                maxSet.insert(nums[i]);
            }
        }

        return *maxSet.begin();
    }
};
```

