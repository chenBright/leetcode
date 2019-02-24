#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        /**
         * 肯定不是回文数：
         * 1. x小于0
         * 2. x整除10
         */
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reverseNum = 0; // 反转数字

        // 反转一半数字
        while (x > reverseNum) {
            int n = x % 10;
            x /= 10;
            reverseNum = reverseNum * 10 + n;
        }

        /**
         * 假设x是回文数，反转一半数字：
         * 如果输入时x位数为偶数，反转后，x == reverseNum
         * 如果输入时x位数为奇数，反转后，reverseNum位数比x多一位，x == reverseNum / 10
         */
        return x == reverseNum || x == reverseNum / 10;
    }
};
