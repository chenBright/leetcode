#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int last = 0;
        int now = 0;
        for (auto num : nums) {
            int tempLast = last;
            last = now;
            now = max(tempLast + num, now);
        }

        return now;
    }
};