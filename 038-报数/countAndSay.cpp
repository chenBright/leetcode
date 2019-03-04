#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string currentS = "";
            char tempCh;
            int count = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (j == 0) { // 第一个字符
                    tempCh = s[j];
                    count = 1;
                    continue;
                }

                if (tempCh == s[j]) { // 字符相同，计数
                    ++count;
                } else { // 不相同，转换为下一字符串，并统计后面字符
                    currentS += intToString(count, tempCh);
                    tempCh = s[j];
                    count = 1;
                }
            }
            currentS += intToString(count, tempCh); // 结束循环时，没有处理的字符
            s = currentS;
        }

        return s;
    }

private:
    string intToString(int count, char ch) {
        stringstream ss;
        string temp;
        ss << count;
        ss >> temp;
        return temp + ch;
    }
};
