#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<int> bitSet;
        unordered_set<string> tmpSet;

        int current = 0;
        for (int i = 0; i < 9; ++i) {
            // 拼接 位
            current = (current << 3) | (s[i] & 7);
        }

        for (int j = 9; j < len; ++j) {
            // 将当前字符的 位 添加到后面
            current = ((current & 0x7ffffff) << 3) | (s[j] & 7);
            if (bitSet.count(current)) {
                tmpSet.insert(s.substr(j - 9, 10));
            } else {
                bitSet.insert(current);
            }
        }

        return vector<string>(tmpSet.begin(), tmpSet.end());
    }
};
