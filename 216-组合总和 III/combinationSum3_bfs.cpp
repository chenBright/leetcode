#include <vector>
using namespace std;

// BFS回溯法
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
        } else if (k < 0 || n < 0) {
            return;
        }

        for (int i = index; i < nums.size() && n - nums[i] >= 0; ++i) {
            resTemp.push_back(nums[i]);
            combinationSum3(k - 1, n - nums[i], i + 1);
            resTemp.pop_back();
        }
    }
};