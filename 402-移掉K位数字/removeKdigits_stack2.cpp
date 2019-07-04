#include <string>
using namespace std;

// 单调栈
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int len = num.size();
        int keep = len - k;
        for (const auto &c : num) {
            while (k != 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                --k;
            }
            
            // 如果 result 不为空，则无论字符是否为 '0'，都添加到 result 后面
            // 如果 result 为空，且 c 为 '0'，则不能添加到 result 后面，因为不能有前置的 '0'
            if (!result.empty() || c != '0') {
                result.push_back(c);
            }
        }

        while (!result.empty() && k != 0) {
            result.pop_back();
            --k;
        }

        return result.empty() ? "0" : result;
    }
};