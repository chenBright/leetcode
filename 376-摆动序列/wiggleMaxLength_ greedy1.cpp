#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        
        int result = 1;

        int i = 1;
        // 找第一个与 nums[0] 不相等的元素
        while (i < len && nums[i] == nums[i - 1]) {
            ++i;
        }

        enum Difference {positive, negative}; // nums[i]- nums[i - 1] 为正还是负 
        Difference diff;
        if (i < len) {
            result = 2;
            diff = nums[i] > nums[0] ? positive : negative;
        } else { // 数组元素全都相等
            return result;
        }

        for (int j = i + 1; j < len; ++j) {
            if (diff == positive) {
                if (nums[j] < nums[j - 1]) {
                    ++result;
                    diff = negative;
                }
            } else {
                if (nums[j] > nums[j - 1]) {
                    ++result;
                    diff = positive;
                }
            }
        }

        return result;
    }
};