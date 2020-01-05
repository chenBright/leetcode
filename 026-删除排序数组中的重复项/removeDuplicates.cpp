#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int frontP = 0; // 指向新数组的最后一个元素
        int endP = 1; // 用于遍历旧数据

        while (endP < nums.size()) {
            if (nums[frontP] != nums[endP]) {
                ++frontP;
                nums[frontP] = nums[endP];
            }
            ++endP;
        }

        return frontP + 1;
    }
};
