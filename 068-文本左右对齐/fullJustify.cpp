#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int length = 0; // 一行单词的总长度
            int j = i;
            while (j < words.size() && length + words[j].size() + j - i <= maxWidth) {
                length += words[j++].size();
            }
            
            string out; // 行结果
            int space = maxWidth - length; // 空格数
            for (int k = i; k < j; ++k) {
                out += words[k];
                if (space > 0) {
                    int tmp;
                    if (j == words.size()) { // 最后一行
                        if (j - k == 1) { // 最后一行最后一个间隔
                            tmp = space;
                        } else {
                            tmp = 1;
                        }
                    } else {
                        if (j - k - 1 > 0) { // 单词间的间隔数
                            if (space % (j - k - 1) == 0) { // 空格对称、均匀
                                tmp = space / (j - k - 1);
                            } else {
                                tmp = space / (j - k - 1) + 1;
                            }
                        } else { // 最后一个间隔
                            tmp = space;
                        }
                    }
                    out.append(tmp, ' ');
                    space -= tmp;
                }
            }
            result.push_back(out);
            i = j;
        }

        return result;
    }
};
