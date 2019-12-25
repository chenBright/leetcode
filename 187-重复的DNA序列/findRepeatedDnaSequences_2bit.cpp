#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<int> bitSet;
        unordered_set<string> tmpSet;

        // A: 00　　C: 01　　G: 10　　T: 11
        // 只需取后 2 位就能唯一表示这些字母
        unordered_map<char, int>m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

        int current = 0;
        for (int i = 0; i < 9; ++i) {
            // 拼接 位
            current = (current << 2) | (m[s[i]]);
        }

        // 滑动窗口
        for (int j = 9; j < len; ++j) {
            // 将当前字符的 位 添加到后面
            // 用 mask = 0x3ffffff 取出后 18 位，在向左移动 2 位，
            // 最后拼接下一个字母的 位
            current = ((current & 0x3ffff) << 2) | (m[s[j]]);
            if (bitSet.count(current)) {
                tmpSet.insert(s.substr(j - 9, 10));
            } else {
                bitSet.insert(current);
            }
        }

        return vector<string>(tmpSet.begin(), tmpSet.end());
    }
};
