#include <vector>
using namespace std;

// DFS回溯法
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        if (k <= 0) {
            return res;
        }

        // 生成数字
        for (int i = 1; i <= 9; ++i) {
            nums.push_back(i);
        }

        combinationSum3(k, n,  0);

        return res;
    }

private:
    vector<int> nums;
    vector<int> resTemp;
    vector<vector<int> > res;

    void combinationSum3(int k, int n, int index) {
        if (k == 0 && n == 0) {
            res.push_back(resTemp);
            return;
        } else if (k < 0 || n < 0 || index >= nums.size() || n - nums[index] < 0) {
            return;
        }

        combinationSum3(k, n, index + 1);

        resTemp.push_back(nums[index]);
        combinationSum3(k - 1, n - nums[index], index + 1);
        resTemp.pop_back();
    }
};