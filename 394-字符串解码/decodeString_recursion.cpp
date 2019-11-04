#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }

private:
    string dfs(string& s, int& i) {
        string result("");
        int length = s.size();
        while (i < length && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                result += s[i];
                ++i;
            } else {
                // 先计算次数
                int count = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    count = count * 10 + (s[i] - '0');
                    ++i;
                }

                // 递归解码
                ++i; // 跳过 "["
                string tmp = dfs(s, i);
                ++i; // 跳过 "]"

                // 拼接
                while (count-- > 0) {
                    result += tmp;
                }
            }
        }

        return result;
    }
};
