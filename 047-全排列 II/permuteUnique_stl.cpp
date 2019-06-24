#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > result;
        if (nums.empty()) {
            return result;
        }

        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        do {
            result.push_back(tmp);
        } while (next_permutation(tmp.begin(), tmp.end()));

        return result;
    }
};
