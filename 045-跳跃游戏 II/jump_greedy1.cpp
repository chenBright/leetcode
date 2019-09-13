#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int length = nums.size();
        int count = 0;
        int i = 0;
        while (i < length - 1) {
            // 在当前位置分别跳出 1 ~ nums[i] 个长度到达 next 位置，
            // 再看在一步最大能达到的位置，找出最大值，此最大值所对应的 next 值即为应该跳到的位置。
            // 还有一种特殊情况，就是如果该次跳跃可以直接跳到最后一个位置，则 next 为 length - 1，即使它不是最大值。
            int maxNext = INT_MIN;
            int next;
            for (int j = 1; j <= nums[i]; ++j) {
                int nextIndex = min(length - 1, i + j);
                if (nextIndex + nums[nextIndex] > maxNext || nextIndex == length - 1) {
                    next = nextIndex;
                    maxNext = nextIndex + nums[nextIndex];
                }
            }
            ++count;
            i = next;
        }

        return count;
    }
};
