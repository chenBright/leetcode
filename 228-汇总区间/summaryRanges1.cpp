#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        int i = 0;
        int j = 0;
        int len = nums.size();
        while (j < len - 1 && i < len) {
            if (nums[j] + 1 != nums[j + 1]) {
                result.push_back(toString(nums, i, j));
                i = j + 1;
            }
            ++j;
        }

        result.push_back(toString(nums, i, j)); // 处理最后一个区间

        return result;
    }

private:
    inline string toString(vector<int> &nums, int i, int j) {
        if (i == j) {
            return to_string(nums[i]);
        } else {
            return to_string(nums[i]) + "->" + to_string(nums[j]);
        }
    }
};
