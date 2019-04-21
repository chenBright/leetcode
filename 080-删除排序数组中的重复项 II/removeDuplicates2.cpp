#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < 2 || nums[i] > nums[length - 2]) {
                nums[length++] = nums[i];
            }
        }

        return length;
    }
};