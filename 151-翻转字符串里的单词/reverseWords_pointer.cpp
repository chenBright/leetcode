#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }

        string result = "";
        auto start = s.rbegin();
        auto end = start;
        while (end != s.rend()) {
            // 跳过空格
            if (*end == ' ') {
                ++end;
                continue;
            }

            start = end;
            // 遍历单词的字母直到遇到空格
            while (start != s.rend() && *start != ' ') {
                ++start;
            }
            // 拷贝单词
            // 需要将反向迭代器转成正向迭代器
            result += string(start.base(), end.base()) + " ";
            end = start;
        }
        // 不返回最后一个空格
        return result.substr(0, result.size() - 1);
    }
};