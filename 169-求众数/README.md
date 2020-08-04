# 169-求众数

## 题目

leetcode：[169-求众数](https://leetcode-cn.com/problems/majority-element/)

## 排序后统计个数

将数组排好序，则统计就会很好完成。排序的时间复杂度为**O(nlogn)**，统计的时间复杂度为**O(n)**，所以该方法的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        sort(nums.begin(), nums.end());

        int num = nums[0];
        int count = 1;
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it) {
            if (num == *it) {
                ++count;

                if (count > nums.size() / 2) {
                    return num;
                }
            } else {
                count = 1;
                num = *it;
            }
        }
        return 0;
    }
};
```



## 使用map统计个数

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        map<int, int> numMap;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (numMap.count(*it)) {
                ++numMap[*it];
            } else {
                numMap[*it] = 1;
            }
        }

        for (map<int, int>::iterator it = numMap.begin(); it != numMap.end(); ++it) {
            if (it->second > nums.size() / 2) {
                return it->first;
            }
        }

        return 0;
    }
};
```

## 基于Partition函数的O(n)的查找第K大的数

数组中有一个数字出现的次数超过了数组长度的一半，那么**如果我们把这个数组排序，那么排序之后位于数组中间的那个数字一定就是那个出现次数超过数组长度一半的数字**。即这个数是中位数，则现在问题变成查找第k大的元素。**快速排序算法**的Partition函数每次都可以确定基准元素的最终位置，则我们可以用快排的思想来找中位数。

最后，还要检查这个中位数的个数是否超过数组元素个数的一半。

Partition函数的时间复杂度为**O(logn)**，检查的时间复杂度也为**O(n)**，所以该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        }

        int n = findKth(nums, 0, len - 1, len / 2);
        if (checkMoerThanHalf(nums, n)) {
            return n;
        }

        return 0;
    }

private:
    // 在数组中找索引为k的元素
    int findKth(vector<int> &nums, int low, int high, int k) {
        int index = Partition(nums, low, high);

        if (index == k) {
            return nums[k];
        } else if (index < k) {
            return findKth(nums, index + 1, high, k);
        } else {
            return findKth(nums, low, index - 1, k);
        }
    }
    int Partition(vector<int> &nums, int low, int high) {
        int i = low, j = high;
        int pivotNum = nums[low]; // 基准元素

        while (i < j) {
            // 从后面开始找，找到第一个不大于基准元素的元素
            while (i < j && nums[j] > pivotNum) {
                --j;
            }
            nums[i] = nums[j];

            // 从前面开始找，找到第一个大于基准元素的元素
            while (i < j && nums[i] <= pivotNum) {
                ++i;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivotNum;
        return i; // 最后的位置 i == j 就是基准元素的最终位置
    }
    // 检查number的个数是否超过数组个数的一半
    bool checkMoerThanHalf(vector<int> nums, int number) {
        int count = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (*it == number) {
                ++count;
            }
        }

        return count > nums.size() / 2 ? true : false;
    }
};
```

## 摩尔投票算法

要充分利用**出现次数超过一半**这个条件

1. 算法在局部变量中定义一个序列元素（num）和一个计数器（count），初始化的情况下计数器为0；
2. 算法依次扫描序列中的元素，当处理元素x的时候，如果计数器为0，那么将x赋值给num，然后将count设置为1；
3. 如果count不为0，那么将num和x比较，如果相等，那么计数器加1；如果不等，那么计数器减1。
4. 理之后，最后存储的num，就是这个序列中最多的元素。

摩尔投票算法的时间复杂度为**O(n)**，检查的时间复杂度也为**O(n)**，所以该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int num = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // 如果 count == 0，则将当前数字作为候选数字。
            if (count == 0) {
                num = nums[i];
                count = 1;
                continue;
            }

            if (num != nums[i]) {
                --count;
            } else {
                ++count;
            }
        }

        return checkMoerThanHalf(nums, num) ? num : 0;
    }

private:
    // 检查number的个数是否超过数组个数的一半
    bool checkMoreThanHalf(vector<int> nums, int number) {
        int count = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (*it == number) {
                ++count;
            }
        }

        return count > nums.size() / 2 ? true : false;
    }
};
```

