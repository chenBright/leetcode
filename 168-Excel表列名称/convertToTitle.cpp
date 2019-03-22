#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }

        string tempStr;
        const int system = 26;
        while (n > 0) {
            --n; // 因为从1开始
            int temp = n % system;
            tempStr.append(1, 'A' + temp - 1);
            n /= system;
        }

        return string(tempStr.rbegin(), tempStr.rend());
    }
};
