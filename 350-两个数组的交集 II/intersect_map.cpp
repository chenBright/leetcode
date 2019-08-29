#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        for (const auto num : nums1) {
            ++m[num];
        }

        for (const auto &num : nums2) {
            if (m.count(num) != 0 && m[num] > 0) {
                result.push_back(num);
                --m[num];
            }
        }

        return result;
    }
};