#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int length = nums.size();
        int count = 0;
        int lastNext = 0;
        int currentNext = 0;
        for (int i = 0; i < length - 1; ++i) {
            currentNext = max(currentNext, i + nums[i]);
            if (i == lastNext) {
                lastNext = currentNext;
                ++count;
                if (currentNext >= length - 1) {
                    break;
                }
            }
        }

        return count;
    }
};
