#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, stack<int> > m; // 记录不是 Bulls 的索引
        int bulls = 0;
        int cows = 0;
        int len = guess.size();
        for (int i = 0; i < len; ++i) {
            char c = secret[i];
            // Bulls
            if (secret[i] == c) {
                ++bulls;
                continue;
            }

            if (m.count(c) == 0) {
                m[c] = stack<int>();
            }
            m[c].push(i);
        }

        for (int j = 0; j < len; ++j) {
            char c = guess[j];
            // 该字符是 Bull 或者 没在 secret 中出现 或者 secret 中已经没有字符与之匹配成 Cow
            if (secret[j] == c || m.count(c) == 0 || m[c].empty()) {
                continue;
            }

            // Cow
            ++cows;
            m[c].pop();
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
