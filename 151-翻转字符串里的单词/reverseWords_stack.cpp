#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }

        stack<string> strStack;
        auto start = s.begin();
        auto end = start;
        while (start != s.end()) {
            // 跳过空格
            if (*start == ' ') {
                ++start;
                continue;
            }

            end = start;
            // 遍历单词的字母知道遇到空格
            while (end != s.end() && *end != ' ') {
                ++end;
            }

            // 拷贝单词到栈中
            strStack.push(string(start, end));
            start = end;
        }

        string result = "";
        // 从栈中取出单词，从而实现翻转字符串里的单词
        while (!strStack.empty()) {
            result += strStack.top() + " ";
            strStack.pop();
        }

        return result.substr(0, result.size() - 1);
    }
};