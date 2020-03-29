#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }

        stack<int> sStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sStack.push(s[i]);
            } else {
                if (sStack.empty()) {
                    return false;
                }

                char c = sStack.top();
                sStack.pop();
                if (s[i] == ')' && c != '(') {
                    return false;
                } else if (s[i] == ']' && c != '[') {
                    return false;
                } else if (s[i] == '}' && c != '{') {
                    return false;
                }
            }
        }

        return sStack.empty();
    }
};
