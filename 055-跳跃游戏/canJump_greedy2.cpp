#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int length = nums.size();
        int dist = 0;
        // dist 表示能跳到最大的位置
        // dist >= i，表示至少跳出本个位置，即 num[i] != 0
        for (int i = 0; i < length && dist >= i; ++i) {
            dist = max(dist, i + nums[i]);
        }

        return dist >= length - 1;
    }
};