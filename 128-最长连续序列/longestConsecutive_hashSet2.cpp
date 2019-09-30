#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> s(nums.begin(), nums.end());

        int result = 0;
        for (const auto &num : nums) {
            if (s.count(num) != 0) {
                s.erase(num);
                int left = num - 1;
                int right = num + 1;

                // (left, right)
                // 找到序列的第一个数字前一个数字
                while (s.count(left) != 0) {
                    s.erase(left--);
                }

                // 找到序列的第一个数字后一个数字
                while (s.count(right) != 0) {
                    s.erase(right++);
                }

                result = max(result, right - left - 1);
            }
        }

        return result;
    }
};