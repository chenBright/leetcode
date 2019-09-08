#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int iStart = -1; // 星号匹配到 s 中的位置
        int jStart = -1; // p 中星号的位置
        while (i < s.size()) {
            if (s[i] == p[j] || p[j] == '?') { // 一对一匹配，两指针同时后移
                ++i;
                ++j;
            } else if (p[j] == '*') {
                // 假设它匹配空串，并且用 startIdx 记录 * 的位置，记录当前字符串的位置，p 后移
                iStart = i;
                jStart = j++;
            } else if (iStart >= 0) { 
                // 当前字符不匹配，并且也没有 *，回溯
                // j 回到 * 的下一个位置
                // iStart 更新到下一个位置
                // i 回到更新后的 match 
                // 这步代表用 * 匹配了一个字符
                i = ++iStart;
                j = jStart + 1;
            } else { // 字符不匹配，也没有 *，返回 false
                return false;
            }
        }

        // 将末尾多余的 * 直接匹配空串 例如 text = ab, pattern = a*******
        while (j < p.size() && p[j] == '*') {
            ++j;
        }

        return j == p.size();
    }
};
