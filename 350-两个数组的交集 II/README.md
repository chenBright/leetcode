# 350-两个数组的交集 II

## 题目

leetcode：[350-两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/)

## Map

使用`Map`记录`nums1`中每个数字出现的次数。遍历`nums2`。如果元素出现在`Map`中，且次数大于0，则将其添加到结果数组中，并将次数减一。

时间复杂度：***O(n + m)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        for (const auto num : nums1) {
            ++m[num];
        }

        for (const auto &num : nums2) {
            if (m.count(num) != 0 && m[num] > 0) {
                result.push_back(num);
                --m[num];
            }
        }

        return result;
    }
};
```

## 排序 + 双指针

先对两个数组排序，使用两个指针分别指向两个数组。

- 如果两个指针所指的数字相等，则添加到结果数组后面，两指针都加一；
- 否则，指向小数字的指针加一。

时间复杂度：***O(n + m)***。

空间复杂度为：***O(1)***。

```c++
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
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
                result.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }

        return result;
    }
};
```

