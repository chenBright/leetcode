#include <vector>
using namespace std;

// BFS 回溯法
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return res;
        }
        subsets(nums, 0, length - 1);

        return res;
    }

private:
    vector<vector<int> > res;
    vector<int> temp;

    void subsets(vector<int> &nums, int left, int right) {
        if (left > right) {
            res.push_back(temp);
            return;
        }

        res.push_back(temp); // 先不考虑后面的元素，先添加当前集合
        // 与后面每个元素分别组成一个集合
        for (int i = left; i <= right; ++i) {
            temp.push_back(nums[i]);
            subsets(nums, i + 1, right);
            temp.pop_back();
        }
    }
};