#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


// 基于Partition函数的 O(n) 的查找第K大的数
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