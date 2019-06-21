#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return "";
        } else if (numerator == 0) {
            return "0";
        }

        int isNegative1 = numerator < 0 ? -1 : 1;
        int isNegative2 = denominator < 0 ? -1 : 1;
        long long n = abs(static_cast<long long>(numerator));
        long long d = abs(static_cast<long long>(denominator));
        long long out = n / d;
        long long remainder = n % d;
        unordered_map<long long, int> m; // 数字 -> 位置
        // 处理整数部分
        string result = to_string(out);
        // 只有一个负数，则结果中有负号
        if (isNegative1 * isNegative2 == -1) {
            result = "-" + result;
        }
        if (remainder == 0) {
            return result;
        }
        result += ".";

        string decimals; // 小数部分
        int position = 0; // 当前数字的位置
        while (remainder != 0) {
            if (m.find(remainder) != m.end()) { // 出现相同的余数，则表示结果为循环小数
                decimals.insert(m[remainder], "(");
                decimals += ")";
                break;
            }

            m[remainder] = position; // 记录该数字出现的位置
            decimals += to_string(remainder * 10 / d);
            remainder = (remainder * 10) % d;
            ++position;
        }

        return result + decimals;
    }
};
