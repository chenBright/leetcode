#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1); // 用于存储结果，避免重复计算
        cache[0] = 1;
        cache[1] = 1;

        return climbStairsRe(n, cache);
    }

private:
    int climbStairsRe(int n, vector<int> &cache) {
        if (cache[n] > 0) {
            return cache[n];
        }

        int res = climbStairsRe(n - 1, cache) + climbStairsRe(n - 2, cache);
        cache[n] = res;
        return res;
    }
};