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
    int index; // 索引值
    string str;
    
    int calculate() {
        int result = 0;
        int len = str.size();
        int op = 1; // 1 表示加号，-1 表示减号

        for (; index < len; ++index) {
            if (str[index] >= '0' && str[index] <= '9') {
                int num = 0;
                while (index < len && str[index] >= '0' && str[index] <= '9') {
                    num = num * 10 + (str[index] - '0');
                    ++index;
                }
                result += op * num;
                --index; // 每次循环会将 i 递增，所以此处要将 i减 1
            } else if (str[index] == '+') {
                op = 1;
            } else if (str[index] == '-') {
                op = -1;
            } else if (str[index] == '(') {
                ++index; // 从括号内的字符开始遍历
                result += op * calculate();
            } else if (str[index] == ')') {
                return result;
            }
            // 跳过空格
        }

        return result;
    }
};