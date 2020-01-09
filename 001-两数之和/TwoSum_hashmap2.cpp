#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

// 哈希表，只需遍历一次
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        // <值, 索引>
        unordered_map<int, int> hashMap;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int anotherNum = target - nums[i]; // 另一个数

            // 存在等于target - nums[i]的数且不是同一个数
            // 否则，插入记录到哈希表
            if (hashMap.count(anotherNum)) {
                result.push_back(i);
                result.push_back(hashMap[anotherNum]); // 另一个数的索引
                break;
            } else {
                hashMap.insert(make_pair(nums[i], i));
            }
        }

        return result;
    }
};