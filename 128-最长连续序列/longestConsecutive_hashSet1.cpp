#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int result = 0;
        for (const auto &num : nums) {
            // 找到连续序列的第一个数字
            if (s.count(num - 1) == 0) {
                int currentNum = num;
                int tmpResult = 1;
                // 统计连续序列的长度
                while (s.count(currentNum + 1) != 0) {
                    ++currentNum;
                    ++tmpResult;
                }

                result = max(result, tmpResult);
            }
        }

        return result;
    }
};
