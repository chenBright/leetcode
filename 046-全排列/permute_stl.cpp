#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        vector<vector<int> > result;
        if (nums.empty()) {
            return result;
        }

        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end()); // next_permutation 要求输入序列为有序
        do {
            result.push_back(tmp);
        } while (next_permutation(tmp.begin(), tmp.end()));

        return result;
    }
};
