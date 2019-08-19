#include <vector>
#include <limits>
using namespace std;

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
