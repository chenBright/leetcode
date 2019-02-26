#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) { // 栈内没有左括号与右括号匹配
                    return false;
                } else {
                    if (ch == ')') {
                        if (st.top() == '(') {
                            st.pop();
                        } else {
                            return false;
                        }
                    } else if (ch == ']') {
                        if (st.top() == '[') {
                            st.pop();
                        } else {
                            return false;
                        }
                    } else if (ch == '}') {
                        if (st.top() == '{') {
                            st.pop();
                        } else {
                            return false;
                        }
                    }
                }
            }
        }

        return st.empty() ? true : false;
    }
};
