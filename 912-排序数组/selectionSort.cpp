#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int minIndex = i;
            // 选择最小的元素
            for (int j = i + 1; j < length; ++j) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            if (nums[minIndex] < nums[i]) {
                swap(nums[minIndex], nums[i]);
            }
        }

        return nums;
    }
};
