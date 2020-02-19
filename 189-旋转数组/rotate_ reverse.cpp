#include <vector>
#include <algorithm>
using namespace std;

// 翻转数组
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        if (k > length) {
            k = k % length;
        }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
