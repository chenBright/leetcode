#include <vector>
using namespace std;

// 厄拉多塞筛法
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> primes(n, true); // 0 ~ n - 1
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                ++count;
                for (int j = 2; i * j < n; ++j) {
                    primes[i * j] = false;
                }
            }
        }

        return count;
    }
};