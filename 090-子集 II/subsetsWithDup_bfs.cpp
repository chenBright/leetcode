#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        sort(nums.begin(), nums.end());
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
            /**
             * i == low 肯定取，表示至少取1个 。
             * 如果nums[low] == nums[low - 1]，
             * [low ... high] 包含了 [low - 1 ... high] 的结果，所以跳过，达到去重的效果
             */
            if (i != left && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            subsets(nums, i + 1, right);
            temp.pop_back();
        }
    }
};