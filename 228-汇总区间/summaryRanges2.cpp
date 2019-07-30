#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        int len = nums.size();
        for (int i = 0, j = 0; j < len; ++j) {
            if (j + 1 <len && nums[j] + 1 == nums[j + 1]) {
                continue;
            }

            if (i == j) {
                result.push_back(to_string(nums[i]));
            } else {
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j + 1;
        }

        return result;
    }
};
