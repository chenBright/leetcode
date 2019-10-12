#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (s.count(i) == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};
