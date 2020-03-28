#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        removeRedundantBlank(s); // 删除多余的空格

        int length = s.size();
        reverse(s.begin(), s.end()); // 翻转整个字符串

        int left = 0;
        int right = 0;
        while (right < length) {
            if (s[right] == ' ') {
                // 翻转单词
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            } else if (right == length - 1) {
                // 翻转最后一个单词
                reverse(s.begin() + left, s.begin() + right + 1);
            }
            ++right;
        }

        return s;
    }

private:
    void removeRedundantBlank(string& s) {
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (!(s[right] == ' ' && (right == 0 || s[right - 1] == ' '))) {
                s[left++] = s[right];
            }
            ++right;
        }

        // 检查最后一个字符是否为空格。
        // 如果是，则删除。
        if (left > 0 && s[left - 1] == ' ') {
            --left;
        }

        s.erase(s.begin() + left, s.end());
    }
};
