#include <vector>
using namespace std;

// 从小的组合开始递增
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k == 0) {
            return result;
        }

        vector<int> tmp(k, 0);

        int i = 0;
        while (i >= 0) {
            ++tmp[i];
            if (tmp[i] > n) {
                --i;
            } else if (i == k - 1) {
                result.push_back(tmp);
            } else {
                ++i;
                tmp[i] = tmp[i - 1]; // 等到下一循环，右边数字至少是左边数字 + 1
            }
        }

        return result;
    }
};