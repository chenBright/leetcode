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

        reverse(nums, 0, length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, length - 1);
    }

private:
    void reverse(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};