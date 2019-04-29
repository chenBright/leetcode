#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


// 基于Partition函数的O(n)的查找第K大的数
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        findKth(nums, 0, nums.size() - 1, k - 1);

        return nums[k - 1];
    }

private:
    void findKth(vector<int> &nums, int low, int high, int k) {
        int index = Partition(nums, low, high);

        if (index == k) {
            return;
        } else if (index < k) {
            findKth(nums, index + 1, high, k);
        } else {
            findKth(nums, low, index - 1, k);
        }
    }
    int Partition(vector<int> &nums, int low, int high) {
        int i = low;
        int j = high;
        int pivotNum = nums[low];  // 基准元素

        while (i < j) {
            // 从后面开始找，找到第一个不小于基准元素的元素
            while (i < j && nums[j] < pivotNum) {
                --j;
            }
            nums[i] = nums[j];

            // 从前面开始找，找到第一个小于基准元素的元素
            while (i < j && nums[i] >= pivotNum) {
                ++i;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivotNum;
        return i;
    }
};