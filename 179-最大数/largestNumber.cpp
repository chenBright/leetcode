#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int length = nums.size();
        vector<string> strs(length);
        for (int i = 0; i < length; ++i) {
            strs[i] = to_string(nums[i]);
        }

         // 从大到小排序
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

         // 后面的数字一定是 0
        if (strs[0] == "0") {
            return "0";
        }

        string str;
        for (const auto& s : strs) {
            str.append(s);
        }

        return str;
    }
};
