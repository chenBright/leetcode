#include <string>
#include <vector>
using namespace std;

// 扫描列
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int strsSize = strs.size();

        if (strsSize == 0) {
            return "";
        } else if (strsSize == 1) {
            return strs[0];
        }

        bool isFind = false;
        for (int i = 0; !isFind; ++i) {
            char temp;
            if (i < strs[0].size()) {
                temp = strs[0][i];
            } else {
                break;
            }

            for (int j = 1; j < strsSize; ++j) {
                if (i < strs[j].size()) {
                    if (temp == strs[j][i]) {
                        if (j == strsSize - 1) { // 字符相等，且已计较了最后一个字符串
                            res += temp;
                        }
                    } else { // 如果不相等，则该字符不属于公共前缀，结束内外循环
                        isFind = true;
                        break;
                    }
                } else { // 有一个字符串已经遍历完，结束内外循环
                    isFind = true;
                    break;
                }
            }
        }

        return res;
    }
};
