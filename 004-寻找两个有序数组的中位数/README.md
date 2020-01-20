# 004-寻找两个有序数组的中位数

## 题目

leetcode：[004-寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)


## 二分查找（分治）

时间复杂度：***O(log(m + n))***。

### 迭代1

参考[4. 寻找两个有序数组的中位数 C / C++](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/)。

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // 保证数组1最短
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci 为第 i 个数组的割，比如 C1 为 2 时表示第 1 个数组只有 2 个元素。
        // LMaxi 为第 i 个数组割后的左元素。
        // RMini 为第 i 个数组割后的右元素。
        // 目前是虚拟加了“#”，所以数组 1 的长度是 2 * n。
        int LMax1, LMax2, RMin1, RMin2, c1, c2, low = 0, high = 2 * n;
        while (low <= high) {
            c1 = (low + high) / 2; //c1 是二分的结果
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2) {
                high = c1 - 1;
            } else if (LMax2 > RMin1) {
                low = c1 + 1;
            } else {
                break;
            }
        }

        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};
```

### 递归2

将上面的迭代实现，改成了递归实现。

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // 保证数组1最短
        if (n > m) {
            // 目前是虚拟加了“#”，所以数组 1 的长度是 2 * m。
            return findMedianSortedArrays(nums2, nums1, 0, 2 * m);
        } else {
            // 目前是虚拟加了“#”，所以数组 1 的长度是 2 * n。
            return findMedianSortedArrays(nums1, nums2, 0, 2 * n);
        }

    }
private:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2, int low, int high) {
        int n = nums1.size();
        int m = nums2.size();

        // Ci 为第 i 个数组的割，比如 C1 为 2 时表示第 1 个数组只有 2 个元素。
        // LMaxi 为第 i 个数组割后的左元素。
        // RMini 为第 i 个数组割后的右元素。
        int LMax1, LMax2, RMin1, RMin2, c1, c2;
        c1 = (low + high) / 2; //c1 是二分的结果
        c2 = m + n - c1;

        LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

        if (low > high) {
            return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
        }

        if (LMax1 > RMin2) {
            return findMedianSortedArrays(nums1, nums2, low, c1 - 1);
        } else if (LMax2 > RMin1) {
            return findMedianSortedArrays(nums1, nums2, c1 + 1, high);
        } else {
            return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
        }
    }
};
```

## 迭代2

参考[详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/)。

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // 保证数组1最短
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int iMin = 0;
        int iMax = m;

        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = (m + n + 1) / 2 - i;

            if (j != 0 && i != m && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            } else if (i != 0 && j != n && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            } else { // 符合要求，并且将边界条件列出来单独考虑。
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }

                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums1[i], nums2[j]);
                }

                // 不能除以 2，否则其结果为 int，忽略了小数。
                return (maxLeft + minRight) / 2.0;
            }
        }

        return 0.0;
    }
};
```

## 查找第K小的数

参考[详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/)。

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;

        // 将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
        return (getKth(nums1, 0, m - 1, nums2, 0, n - 1, left) + getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) / 2;

    }
private:
    double getKth(vector<int> &nums1, int start1, int end1, vector<int> &nums2, int start2, int end2, int k) {
        int length1 = end1 -  start1 + 1;
        int length2 = end2 - start2 + 1;

        // 保证数组 1 最短，这样就能保证如果有数组空了，一定是 length == 0。
        if (length1 > length2) {
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        }

        if (length1 == 0) {
            return nums2[start2 + k - 1];
        }

        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }

        int i = start1 + min(length1, k / 2) - 1;
        int j = start2 + min(length2, k / 2) - 1;

        if (nums1[i] < nums2[j]) {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        } else {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
    }
};
```

