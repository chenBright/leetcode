#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) : length(nums.size()), sums(length, vector<int>(length, INT_MIN)) {
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sums[i][i] = nums[i];
            sum += nums[i];
            sums[0][i] = sum; // 计算 0……i 的和
        }
    }
    
    int sumRange(int i, int j) {
        if (i >= length || j >= length || i > j) {
            return INT_MIN;
        }

        // 如果已保存 i……j 的和，则直接返回
        if (sums[i][j] != INT_MIN) {
            return sums[i][j];
        }

        int sum =  sumRange(i, j - 1) + sums[j][j];
        sums[i][j] = sum; // 保存

        return sum;
    }

private:
    int length;
    vector<vector<int> > sums; // 保存 i……j 的和
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */