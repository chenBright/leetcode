# 349-两个数组的交集

## 题目

leetcode：[349-两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays/)

## Set

使用集合`s1`保存`nums1`中的元素，然后遍历`nums2`。

- 如果元素存在`s1`中，则将其插入到结果集合`s2`中；
- 否则，跳过。

最后，将集合`s2`转成`vector`返回。

时间复杂度：**O(n + m)**。

空间复杂度为：**O(n + m)**。

```c++
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2;
        for (const auto &num : nums2) {
            if (s1.count(num) != 0) {
                s2.insert(num);
            }
        }

        return vector<int>(s2.begin(), s2.end());
    }
};
```

## 排序 + 双指针

先对两个数组排序，使用两个指针分别指向两个数组。

- 如果两个指针所指的数字相等，且结果数组为空或者该数组不等于结果数组的最后一个元素，则添加到结果数组后面；
- 否则，指向小数字的指针 + 1。

时间复杂度：**O(max(nlogn, mlogm))**。

空间复杂度为：**O(1)**。

```c++
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                if (result.empty() || nums1[i] != result.back()) {
                    result.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
        }

        return result;
    }
};
```

## 排序 + 二分查找

先对`nums1`排序，然后遍历`nums2`，使用二分查找在`nums1`中查找遍历到的元素。

- 如果查找成功，则将其插入到结果集合`s`中；
- 否则，跳过。

最后，将集合`s`转成`vector`返回。

时间复杂度：**O(max(nlogn, mlogm))**。

空间复杂度为：**O(n)**。

```c++
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());

        unordered_set<int> s;
        for (const auto &num : nums2) {
            if (binarySearch(nums1, num)) {
                s.insert(num);
            }
        }

        return vector<int>(s.begin(), s.end());
    }

private:
    bool binarySearch(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
```

