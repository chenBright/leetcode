#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计数字出现的次数
        unordered_map<int, int> num2Count; // <数字， 次数>
        for (const auto& n : nums) {
            ++num2Count[n];
        }

        // 默认从小到大排序
        map<int, vector<int> > count2Num; // <次数，数字>
        for (const auto& it : num2Count) {
            count2Num[it.second].push_back(it.first);
        }

        vector<int> result;
        for (auto count2NumIt = count2Num.rbegin(); count2NumIt != count2Num.rend(); ++count2NumIt) {
            for (int i = 0; i < count2NumIt->second.size(); ++i) {
                result.push_back(count2NumIt->second[i]);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
