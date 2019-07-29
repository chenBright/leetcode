#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        index = 0;
        str = s;
        return calculate();
    }
private:
    int index;
    string str;

    int calculate() {
        int result = 0;
        int len = str.size();
        int op = 1; // 1 表示加号，-1 表示减号
        int num = 0;

        for (; index < len; ++index) {
            if (str[index] >= '0' && str[index] <= '9') {
                num = num * 10 + (str[index] - '0');
            } else if (str[index] == '+' || str[index] == '-') {
                result += op * num;
                num = 0;
                op = str[index] == '-' ? -1 : 1;
            } else if (str[index] == '(') {
                ++index; // 从括号内的字符开始遍历
                result += op * calculate();
            } else if (str[index] == ')') {
                result += op * num;
                return result;
            }
            // 跳过空格
        }

        return result + op * num; // 最后一个数字在循环中没计算
    }
};