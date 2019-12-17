#include <vector>
using namespace std;

// BFS 回溯法
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> tmpResult;
        subsets(nums, result, tmpResult, 0);

        return result;
    }

private:
    void subsets(vector<int>& nums, vector<vector<int> >& result, vector<int>& tmpResult, int index) {
        if (index == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        // 先不考虑后面的元素，先将当前集合当做子集添加当前集合。
        result.push_back(tmpResult);
        // 与后面每个元素分别组成一个集合，例如
        // tmpResult = [1]，则组成两个集合：
        // [1, 2]、[1, 3]。
        for (int i  = index; i < nums.size(); ++i) {
            tmpResult.push_back(nums[i]);
            subsets(nums, result, tmpResult, ++index);
            tmpResult.pop_back();
        }
    }
};