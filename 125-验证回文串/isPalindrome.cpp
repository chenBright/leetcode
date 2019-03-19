#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        int left = 0;
        int right = 0;
        while ( left < right) {
            if (!isAlphanum(s[left])) { // 跳过
                ++left;
            } else if (!isAlphanum(s[right])) { // 跳过
                --right;
            } else if (tolower(s[left]) != tolower(s[right])) { // 字符不相同
                return false;
            } else { // 字符相同，则继续遍历
                ++left;
                --right;
            }
        }

        return true;
    }

private:
    // 是否为数字或者字母
    bool isAlphanum(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
};