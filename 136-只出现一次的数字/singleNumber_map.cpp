#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        map<int, int> m;
        auto it = nums.begin();
        while (it != nums.end()) {
            if (m.count(*it)) {
                ++m[*it];
            } else {
                m[*it] = 1;
            }
            ++it;
        }

        it = nums.begin();
        while (it != nums.end()) {
            if (m[*it] == 1) {
                return *it;
            }
            ++it;
        }

        return -1;
    }
};