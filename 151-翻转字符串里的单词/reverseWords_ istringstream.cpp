#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string tmp;
        is >> s; // 从流中获取一个单词
        while (is >> tmp) {
            s = tmp + " " + s;
        }
        
        return (s.empty() || s[0] == ' ') ? "" : s;
    }
};