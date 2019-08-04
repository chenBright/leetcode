#include <stack>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num / 10 != 0) { // num 不是个位数
            int sum = 0;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }

        return num;
    }
};