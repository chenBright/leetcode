#include <vector>
#include <limits>
using namespace std;

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
