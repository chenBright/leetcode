#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> countStack;
    
        int count = 0;
        string tmpStr("");
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                count = count * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                countStack.push(count);
                strStack.push(tmpStr); // 当前层（[]）暂时的结果
                count = 0;
                tmpStr.clear();
            } else if (s[i] == ']') {
                int k = countStack.top();
                countStack.pop();
                for (int j = 0; j < k; ++j) {
                    strStack.top() += tmpStr;
                }
                tmpStr = strStack.top();
                strStack.pop();
            } else {
                tmpStr += s[i];
            }
        }

        return strStack.empty() ? tmpStr : strStack.top();
    }
};
