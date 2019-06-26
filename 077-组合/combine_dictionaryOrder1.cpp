#include <vector>
using namespace std;

// 字典序
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k == 0) {
            return result;
        }

        vector<int> tmp(k + 1);
        for (int i = 0; i < k; ++i) {
            tmp[i]= i + 1; 
        }
        tmp[k] = n + 1; // 哨兵

        int j = 0;
        while (j < k) {
            result.push_back(vector<int>(tmp.begin(), tmp.end() - 1));

            j = 0;
            while (j < k && tmp[j] + 1 == tmp[j + 1]) {
                tmp[j] = j + 1; // TODO 不懂
                ++j;
            }
            ++tmp[j];
        }

        return result;
    }
};