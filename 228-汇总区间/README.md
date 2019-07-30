# 228-汇总区间

## 题目

leetcode：[228-汇总区间](https://leetcode-cn.com/problems/summary-ranges/)

## 双指针

使用两个指针，一个指针`i`指向区间的起点，一个指针`j`指向区间终点。指针`j`每次都从起点开始遍历，知道遍历到`nums[j] + 1 ] != nums[j + 1]`为止。

时间复杂度：***O(n)***。 

### 实现1

```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        int i = 0;
        int j = 0;
        int len = nums.size();
        while (j < len - 1 && i < len) {
            if (nums[j] + 1 != nums[j + 1]) {
                result.push_back(toString(nums, i, j));
                i = j + 1;
            }
            ++j;
        }

        result.push_back(toString(nums, i, j)); // 处理最后一个区间

        return result;
    }

private:
    inline string toString(vector<int> &nums, int i, int j) {
        if (i == j) {
            return to_string(nums[i]);
        } else {
            return to_string(nums[i]) + "->" + to_string(nums[j]);
        }
    }
};
```

### 实现2

```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        int len = nums.size();
        for (int i = 0, j = 0; j < len; ++j) {
            if (j + 1 <len && nums[j] + 1 == nums[j + 1]) {
                continue;
            }

            if (i == j) {
                result.push_back(to_string(nums[i]));
            } else {
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j + 1;
        }

        return result;
    }
};
```

