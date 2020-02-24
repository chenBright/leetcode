#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int i = left;
        int j = right;
        int pivot = nums[i];
        while (i < j) {
            // 因为 i 空出来了，所以先从后面开始。
            // 找到小于等于 pivot 的元素
            while (i < j && nums[j] > pivot) {
                --j;
            }
            if (i == j) {
                break;
            }
            nums[i] = nums[j];
            ++i;

            // 找到大于 pivot 的元素
            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            if (i == j) {
                break;
            }
            nums[j] = nums[i];
            --j;
        }
        nums[i] = pivot;

        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
};