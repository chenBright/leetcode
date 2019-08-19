#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m; // 记录不是 Bulls 的索引
        int bulls = 0;
        int cows = 0;
        int len = guess.size();
        for (int i = 0; i < len; ++i) {
            // Bulls
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                // 该字符在 guess 前面（index < i）出现，
                // secret 现在才有字符与之匹配
                if (m[secret[i]]++ < 0) {
                    ++cows;
                }

                // 该字符在 secret 前面（index < i）出现，
                // guess 现在才有字符与之匹配
                if (m[guess[i]]-- > 0) {
                    ++cows;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
