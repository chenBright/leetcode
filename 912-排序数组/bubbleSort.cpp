#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int flag = true; // 假设剩下的元素有序。
            for (int j = 0; j < length - 1 - i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    flag = false; // 无序
                }
            }
            if (flag) {
                break;
            }
        }

        return nums;
    }
};