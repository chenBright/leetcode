#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int start = 0;
        stack<int> indexStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                indexStack.push(i);
            } else if (s[i] == ')') {
                if (indexStack.empty()) {
                    // 不匹配
                    start = i + 1;
                } else {
                    indexStack.pop();
                    // 更新括号匹配长度
                    // i - (indexStack.top() + 1) + 1 = i - indexStack.top()，其中s[indexStack.top() + 1] 与 s[i] 匹配
                    result = indexStack.empty() ? max(result, i - start + 1) : max(result, i - indexStack.top());
                }
            }
        }

        return result;
    }
};
