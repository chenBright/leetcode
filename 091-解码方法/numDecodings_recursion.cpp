#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();

        if (length == 0) {
            return 1;
        } 
        // 第一个字符为'0'，不能解码
        if (s[0] == '0') { 
            return 0;
        }
        
        if (length == 1) {
            return 1;
        } 

        int num = (s[0] - '0') * 10 + (s[1] - '0');

        if (num > 26) { // 大于26，只能解码一个字符
            return numDecodings(s.substr(1)); 
        } else {
            return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
        }
    }
};
