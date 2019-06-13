#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) {
            result.push_back("");
        } else {
            for (int i = 0; i < n; ++i) {
                for (const auto &left : generateParenthesis(i)) { // 存在重复计算
                    for (const auto &right : generateParenthesis(n - 1 - i)) { // 存在重复计算
                        result.push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return result;
    }
};
