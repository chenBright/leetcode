#include <string>
#include <vector>
using namespace std;

// 分治
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int> > memory(s.size(), vector<int>(t.size(), -1));
        return numDistinct(s, 0, t, 0, memory);
    }

private:
    int numDistinct(string &s, int sIndex, string &t, int tIndex, vector<vector<int> > &memory) {
        // T 是空串，选法就是 1 种
        if (tIndex == t.size()) {
            return 1;
        }

        // S 是空串，选法是 0 种
        if (sIndex == s.size()) {
            return 0;
        }

        if (memory[sIndex][tIndex] != -1) {
            return memory[sIndex][tIndex];
        }

        // 如果 s[sIndex] == t[tIndex]，则
        // 1. 在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex + 1 ... tLen - 1]，记为 n1；
        // 2. 在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex ... tLen - 1]，记为 n2。
        // 最后结果为 n1 + n2。
        // 如果 s[sIndex] == t[tIndex]，则在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex ... tLen - 1]。
        int count = 0;
        if (s[sIndex] == t[tIndex]) {
            count = numDistinct(s, sIndex + 1, t, tIndex + 1, memory);
        }
        count += numDistinct(s, sIndex + 1, t, tIndex, memory);

        memory[sIndex][tIndex] = count;

        return count;
    }
};
