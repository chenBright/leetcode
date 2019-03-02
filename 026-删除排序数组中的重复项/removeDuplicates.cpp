#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int frontP = 0; // 指向新数组的最后一个元素
        int endP = 1; // 用于遍历旧数据

        while (frontP < len && endP < len) {
            if (nums[frontP] != nums[endP]) {
                ++frontP;
                nums[frontP] = nums[endP];
            }
            ++endP;
        }

        return frontP + 1;
    }
};