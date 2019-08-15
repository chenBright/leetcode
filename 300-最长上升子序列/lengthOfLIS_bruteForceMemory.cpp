#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// ????????????
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<vector<int> > memory(nums.size(), vector<int>(nums.size(), -1));
        return lengthOfLIS(nums, -1, 0, memory);
    }
private:
    int lengthOfLIS(vector<int> &nums, int previousPosition, int currentPositon, vector<vector<int> > &memory) {
        if (currentPositon >= nums.size()) {
            return 0;
        }

        if (memory[previousPosition + 1][currentPositon] >= 0) {
            return memory[previousPosition + 1][currentPositon];
        }

        int length1 = 0;
        if (previousPosition < 0 || nums[previousPosition] < nums[currentPositon]) {
            length1 = 1 + lengthOfLIS(nums, currentPositon, currentPositon + 1, memory);
        }

        int length2 = lengthOfLIS(nums, previousPosition, currentPositon + 1, memory);

        memory[previousPosition + 1][currentPositon] = max(length1, length2);

        return memory[previousPosition + 1][currentPositon];
    }
};
