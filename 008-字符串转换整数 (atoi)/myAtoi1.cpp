#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str == "") {
            return 0;
        }

        int len = str.size();

        int i = 0;
        // 跳过开头的空格
        while (i < len && str[i] == ' ') {
            ++i;
        }
        
        // 是否为负数
        bool isNegative = false;
        if (str[i] == '-') {
            isNegative = true;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        // 转换为整型
        double sum = 0; // 取 double，为了处理溢出的情况
        while (i < len && (str[i] >= '0' && str[i] <= '9')) {
            sum = sum * 10 + charToNum(str[i]);
            ++i;
        }

        // 负数
        if (isNegative) {
            sum = -sum;
        }

        // 溢出
        if (sum > INT_MAX) {
            sum = INT_MAX;
        } else if (sum < INT_MIN) {
            sum = INT_MIN;
        }

        return sum;
    }

private:
    int charToNum(char c) {
        return c - '0';
    }
};
