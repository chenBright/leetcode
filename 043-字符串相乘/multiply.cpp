#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") {
            return "0";
        }

        int length1 = num1.size();
        int length2 = num2.size();
        string result(length1 + length2, '0');
        for (int i = length1 - 1; i >= 0; --i) {
            for (int j = length2 - 1; j >= 0; --j) {
                // 两数相乘，再加上原低位数值
                int tmp = charToInt(num1[i]) * charToInt(num2[j]) + charToInt(result[i + j + 1]);
                result[i + j] += tmp / 10;
                result[i + j + 1] = tmp % 10 + '0'; // + '0'，将低位转成字符
            }
        }

        auto index = result.find_first_not_of('0'); // 查找第一个不是'0'的元素的位置

        return index != string::npos ? result.substr(index) : "0";
    }

private:
    inline int charToInt(const char c) {
        return c - '0';
    }
};
