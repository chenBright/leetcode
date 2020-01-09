#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

// 哈希表，只需遍历两次
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        // <值, 索引>
        unordered_map<int, int> hashMap;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            hashMap.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < len; ++i) {
            int anotherNum = target - nums[i]; // 另一个数
            // 存在等于 target - nums[i] 的数且不是同一个数
            if (hashMap.count(anotherNum) && i != hashMap[anotherNum]) {
                result.push_back(i);
                result.push_back(hashMap[anotherNum]); // 另一个数的索引
                break;
            }
        }

        return result;
    }
};