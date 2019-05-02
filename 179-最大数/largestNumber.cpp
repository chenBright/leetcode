#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string res = "";
        if (nums.empty()) {
            return res;
        }

        sort(nums.begin(), nums.end(), compare); // 从大到小排序

        if (nums[0] == 0) { // 后面的数字一定是0
            return "0";
        }

        for (const auto &num : nums) {
            res += to_string(num);
        }

        return res;
    }

    static bool compare(const int &a, const int &b) {
        string aStr = to_string(a);
        string bStr = to_string(b);
        long long ab = stoll(aStr + bStr);
        long long ba = stoll(bStr + aStr);

        return ab > ba;
    }
};