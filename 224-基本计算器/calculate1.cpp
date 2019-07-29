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

        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < len && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                result += op * num;
                --i; // 每次循环会将 i 递增，所以此处要将 i减 1
            } else if (s[i] == '+') {
                op = 1;
            } else if (s[i] == '-') {
                op = -1;
            } else if (s[i] == '(') {
                // 将括号前面计算的结果压入栈中保存
                nums.push(result);
                nums.push(op);
                result = 0;
                op = 1;
            } else if (s[i] == ')') {
                // 将括号前面计算的结果从栈中弹出，并加上括号中的计算结果                
                op = nums.top();
                nums.pop();
                result = result * op + nums.top();
                nums.pop();
            }
            // 跳过空格
        }

        return result;
    }
};