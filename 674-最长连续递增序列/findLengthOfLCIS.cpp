#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int result = 1;
        int tmp = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++tmp;
            } else {
                tmp = 1;
            }
            result = max(result, tmp);
        }

        return result;
    }
};
