#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        sort(nums.begin(), nums.end());

        int num = nums[0];
        int count = 1;
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it) {
            if (num == *it) {
                ++count;

                if (count > nums.size() / 2) {
                    return num;
                }
            } else {
                count = 1;
                num = *it;
            }
        }
        return 0;
    }
};