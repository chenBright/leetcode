#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        vector<int> result;
        unordered_map<int, int> m;
        for (const auto &num : nums) {
            if (m.count(num)) {
                m[num]++;
            } else {
                m[num] = 1;
            }
        }

        for (const auto &num : nums) {
            if (m[num] == 1) {
                result.push_back(num);
            }
        }

        return result;
    }
};