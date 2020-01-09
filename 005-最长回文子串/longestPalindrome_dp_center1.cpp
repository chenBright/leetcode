#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // indexs[0] 为回文串起点，indexs[1] 为回文串终点
        vector<int> indexs(2, 0);

        for (int i = 1; i < s.size(); ++i) {
            // 以 s[i] 为中心
            expandAroundCenter(s, i - 1, i + 1, indexs);
            // 以 s[i - 1]、s[i] 为中心
            expandAroundCenter(s, i - 1, i, indexs);
        }

        return s.substr(indexs[0], indexs[1] - indexs[0] + 1);
    }

private:
    // left 向左扩散，right 向又扩散，找到最长回文串。
    void expandAroundCenter(string &s, int left, int right, vector<int> &indexs) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        ++left;
        --right;
        if (right - left >= indexs[1] - indexs[0]) {
            indexs[0] = left;
            indexs[1] = right;
        }
    }
};
