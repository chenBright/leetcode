#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return vector<vector<int> >(1, vector<int>());
        }

        vector<vector<int> > result;
        int first = nums[0];
        nums.erase(nums.begin());
        vector<vector<int> > words = permute(nums);
        for (auto &word : words) {
            // 插入到 word.size() + 1 个位置上
            for (int i = 0; i <= word.size(); ++i) {
                word.insert(word.begin() + i, first);
                result.push_back(word);
                word.erase(word.begin() + i);
            }
        }

        return result;
    }
};
