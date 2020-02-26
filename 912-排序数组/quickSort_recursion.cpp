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


        int index = paritition(nums, left, right);
        
        quickSort(nums, left, index - 1);
        quickSort(nums, index + 1, right);
    }

    int paritition(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return left;
        }

        int pivot = nums[left];
        while (left < right) {
            // 因为 left 空出来了，所以先从后面开始。
            // 找到小于等于 pivot 的元素
            while (left < right && nums[right] > pivot) {
                --right;
            }
            if (left == right) {
                break;
            }
            nums[left++] = nums[right];

            // 找到大于 pivot 的元素
            while (left < right && nums[left] <= pivot) {
                ++left;
            }
            if (left == right) {
                break;
            }
            nums[right--] = nums[left];
        }
        nums[left] = pivot;

        return left;
    }
};
