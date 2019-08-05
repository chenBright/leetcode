#include <stack>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        stack<int> tmp;
        while (num != 0) {
            tmp.push(num % 10);
            num /= 10;
        }

        int result = 0;
        while (!tmp.empty()) {
            result += tmp.top();
            tmp.pop();
            // 如果 result 大于等于 10，则将十位压回栈中，留下个位
            if (result >= 10) {
                tmp.push(result / 10);
                result %= 10;
            }
        }

        return result;
    }
};