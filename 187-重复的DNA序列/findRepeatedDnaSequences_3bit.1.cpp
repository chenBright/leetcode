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


        // A, C, G, T 的 ASCII 码用二进制来表示：
        // A: 0100 0001　　C: 0100 0011　　G: 0100 0111　　T: 0101 0100
        // 只需取后 3 位就能唯一表示这些字母
        int current = 0;
        for (int i = 0; i < 9; ++i) {
            // 拼接 位
            current = (current << 3) | (s[i] & 7);
        }

        // 滑动窗口
        for (int j = 9; j < len; ++j) {
            // 将当前字符的 位 添加到后面
            // 用 mask = 0x7ffffff 取出后 27 位，在向左移动 3 位，
            // 最后拼接下一个字母的 位
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
