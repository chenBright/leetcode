#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int len = s.size();
        char op = '+'; // 运算符
        stack<int> numStack;

        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }

            // 不能与前面的 if 合并
            // i == len - 1 表示遍历完字符串，立即计算最后的运算，因为最后的运算可能是乘法或者除法
            // 如果与前面的 if 合并，则不会处理这种情况
            if ((s[i] < '0' && s[i] != ' ') || i == len - 1) {
                if (op == '+') {
                    numStack.push(num);
                } else if (op == '-') {
                    numStack.push(-num);
                } else if (op == '*' || op == '/') {
                    num = op == '*' ? numStack.top() * num : numStack.top() / num;
                    numStack.pop();
                    numStack.push(num);
                }
                op = s[i]; // 更新运算符
                num = 0;
            }
        }

        int result = 0;
        while (!numStack.empty()) {
            result += numStack.top();
            numStack.pop();
        }

        return result;
    }
};