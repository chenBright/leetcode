#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                ++m[nums[i]];
            } else {
                m[nums[i]] = 1;
            }
        }

        for (const auto &n : m) {
            if (n.second == 1) {
                return n.first;
            }
        }

        return -1;
    }
};