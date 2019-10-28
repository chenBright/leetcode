#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计数字出现的次数
        unordered_map<int, int> m; // <数字， 次数>
        for (const auto& n : nums) {
            ++m[n];
        }

        priority_queue<pair<int, int> > q; // <次数，数字>
        for (const auto& it : m) {
            q.push({it.second, it.first});
        }

        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = q.top().second;
            q.pop();
        }

        return result;
    }
};
