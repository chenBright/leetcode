#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int len = s.size();
        int op = 1; // 1 表示加号，-1 表示减号
        stack<int> nums;
        int num = 0;

        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                result += op * num;
                num = 0;
                op = s[i] == '-' ? -1 : 1;
            } else if (s[i] == '(') {
                // 将括号前面计算的结果压入栈中保存
                nums.push(result);
                nums.push(op);
                result = 0;
                op = 1;
            } else if (s[i] == ')') {
                result += op * num; // 加上括号内的最后一个数字
                num = 0;

                // 将括号前面计算的结果压入栈中保存
                op = nums.top();
                nums.pop();
                result = result * op + nums.top();
                nums.pop();
            }
            // 跳过空格
        }

        return result + op * num; // 最后一个数字在循环中没计算
    }
};