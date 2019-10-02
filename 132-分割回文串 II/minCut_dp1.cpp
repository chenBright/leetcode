#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        vector<vector<bool> > dp1(length, vector<bool>(length, false));
        vector<int> dp2(length);
        for (int i =0; i < length; ++i) {
            dp2[i] = i; // 分割成 i + 1 个字母
            for (int j = 0; j <= i; ++j) {
                if (s[i] ==s[j] && (i - j < 2 || dp1[j + 1][i - 1])) {
                    dp1[j][i] = true;
                    // j == 0，即 [0 ... i] 是回文字符串，则不需要分割，为 0；
                    // 否则，在
                    // - 已经找到的 [0 ... i] 最小分割方案；
                    // - [0 ... j - 1]、[j ... i] 分割方案；
                    // 中，去最小的方案。
                    dp2[i] = j == 0 ? 0 : min(dp2[i], dp2[j - 1] + 1);
                }
            }
        }

        return dp2[length - 1];
    }
};
