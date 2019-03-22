#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

// 哈希表，只需遍历一次
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if (numbers.empty()) {
            return res;
        }

        // <值, 索引>
        unordered_map<int, int> hashMap;
        int len = numbers.size();
        for (int i = 0; i < len; ++i) {
            int anotherNum = target - numbers[i]; // 另一个数

            // 存在等于target - numbers[i]的数且不是同一个数
            // 否则，插入记录到哈希表
            if (hashMap.count(anotherNum)) {
                res.push_back(hashMap[anotherNum] + 1); // 另一个数的索引，该索引先插入hashMap中，则其索引比较小，所以先放到结果中
                res.push_back(i + 1);
                break;
            } else {
                hashMap.insert(make_pair(numbers[i], i));
            }
        }

        return res;
    }
};