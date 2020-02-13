#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();

        if (length1 > length2) {
            return false;
        }

        vector<int> m1(26, 0); // 记录 s1 中字母的个数
        vector<int> m2(26, 0); // 记录 s2 上滑动窗口内字母的个数

        for (int i = 0; i < length1; ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }

        if (m1 == m2) {
            return true;
        }

        for (int j = length1; j < length2; ++j) {
            // 移动滑动窗口，大小 = length1
            ++m2[s2[j] - 'a'];
            --m2[s2[j - length1] - 'a'];

            if (m1 == m2) {
                return true;
            }
        }

        return false;
    }
};
