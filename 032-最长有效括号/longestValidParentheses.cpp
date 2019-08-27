#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else if (s[i] == ')') {
               ++right;
            }
            if (left == right) {
                result = max(result, right * 2);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (s[j] == '(') {
                ++left;
            } else if (s[j] == ')') {
                ++right;
            }
            if (left == right) {
                result = max(result, left * 2);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return result;
    }
};
