#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) : length(nums.size()), sums(length, INT_MIN) {
        if (length == 0) {
            return;
        }

        sums[0] = nums[0];
        for (int i = 1; i < length; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i >= length || j >= length || i > j) {
            return INT_MIN;
        }

        if (i == 0) {
            return sums[j];
        } else {
            return sums[j] - sums[i - 1];
        }
    }

private:
    int length;
    vector<int> sums; // 保存 i……j 的和
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */