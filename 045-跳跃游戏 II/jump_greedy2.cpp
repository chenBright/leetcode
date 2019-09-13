#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int length = nums.size();
        int count = 0;
        int i = 0; // 当前所在的位置
        int currentNext = 0; // 当前能跳到的最远的位置
        while (currentNext < length) {
            int previousNext = currentNext;
            for (; i < previousNext; ++i) {
                currentNext = max(currentNext, i + nums[i]);
            }
            ++count;

            // 跳不到最后一个位置
            if (previousNext == currentNext) {
                return -1;
            }
        }

        return count;
    }
};
