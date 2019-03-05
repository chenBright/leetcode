#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }

        int i;
        for (i = s.size() - 1; s[i] == ' ' && i >= 0; --i); // 跳过空格

        if (i < 0) { // 全是空格
            return 0;
        }

        int count = 0;
        for (; s[i] != ' ' && i >= 0; --i) {
            ++count;
        }

        return count;
    }
};