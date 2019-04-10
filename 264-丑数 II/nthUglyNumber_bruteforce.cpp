#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return -1;
        }

        int num = 0;
        int count = 1;
        while (count <= n) {
            ++num;
            if (isUglyNumber(num)) {
                ++count;
            }
        }

        return num;
    }

private:
    // 判断n是不是丑数
    bool isUglyNumber(int n) {
        if (n <= 0) {
            return false;
        }

        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 5 == 0) {
                n /= 5;
            } else {
                return false;
            }
        }

        return true;
    }
};