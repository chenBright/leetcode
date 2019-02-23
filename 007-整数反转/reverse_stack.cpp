#include <queue>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        queue<int> tempQ;
        int res = 0;

        while (x != 0) {
            int n = x % 10;
            x /= 10;
            tempQ.push(n);
        }

        while (!tempQ.empty()) {
            res = res * 10 + tempQ.front();
            tempQ.pop();
            // 判断溢出
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tempQ.front() == 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && tempQ.front() == -8)) {
                return 0;
            }
        }

        return res;
    }
};