#include <vector>
using namespace std;

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
        int pivotNum = nums[low]; // 基准元素

        while (low < high) {
            // 因为 low 位置的元素用于基准元素， low 位置先空出来，所以要先从后面开始找。            

            // 从后面开始找，找到第一个不大于基准元素的元素
            while (low < high && nums[high] > pivotNum) {
                --high;
            }
            nums[low] = nums[high];

            // 从前面开始找，找到第一个大于基准元素的元素
            while (low < high && nums[low] <= pivotNum) {
                ++low;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivotNum;
        return low; // 最后的位置 i == j 就是基准元素的最终位置
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