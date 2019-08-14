#include <vector>
using namespace std;

// 快慢指针
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        for (int i = 0; i != slow; i = nums[i]) {
            slow = nums[slow];
        }

        return slow;
    }
};
