#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        if (n == 0) {
            return;
        }

        int i = m + n - 1;
        int j = m - 1;
        int k = n - 1;
        // 从后往前确定元素
        while (j >= 0 && k >= 0) {
            nums1[i--] = nums1[j] > nums2[k] ? nums1[j--] : nums2[k--];
        }

        // nums2还有元素，将剩下的元素复制到nums1中
        if (j < 0) {
            while (k >= 0) {
                nums1[i--] = nums2[k--];
            }
        }
    }
};