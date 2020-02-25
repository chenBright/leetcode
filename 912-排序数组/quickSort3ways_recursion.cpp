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

        auto indexs = paritition(nums, left, right);

        quickSort(nums, left, indexs.first);
        quickSort(nums, indexs.second, right);
    }

    pair<int, int> paritition(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return make_pair(left, left);
        }

        int i = left;
        int j = right;
        int k = i + 1;
        while (k <= j) {
            // 小于 pivot 的范围：[low, i - 1]
            // 等于 pivot 的范围：[i, k]
            // 大于 pivot 的范围：[j + 1, high]
            if (nums[k] < nums[i]) {
                swap(nums[k++], nums[i++]);
            } else if (nums[k] > nums[i]) {
                // 因为 nums[j] 未比较，所以 k 不变。下一循环时，再比较。
                swap(nums[k], nums[j--]);
            } else {
                ++k;
            }
        }

        return make_pair(i - 1, j + 1);
    }
};
