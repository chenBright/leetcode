#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计数字出现的次数
        unordered_map<int, int> m; // <数字， 次数>
        for (const auto& n : nums) {
            ++m[n];
        }

        // 桶排序
        vector<vector<int> > buckets(nums.size() + 1); // <次数，数字>
        for (const auto& it : m) {
            buckets[it.second].push_back(it.first); 
        }

        vector<int> result;
        for (int i = nums.size(); i >= 0; --i) {
            for (int j= 0; j < buckets[i].size(); ++j) {
                result.push_back(buckets[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
