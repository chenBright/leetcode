#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if (n == 0 || k == 0) {
            return result;
        }

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }

        combineRecursion(nums, k);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;

    void combineRecursion(vector<int> nums, int k) {
        if (tmpResult.size() >= k) {
            result.push_back(tmpResult);
            return;
        }

        if (nums.size() < k - tmpResult.size()) {
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp(nums.begin() + i + 1, nums.end());
            tmpResult.push_back(nums[i]);
            combineRecursion(tmp, k);
            tmpResult.pop_back();
        }
    }
};