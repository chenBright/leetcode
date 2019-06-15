#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > result;
        if (strs.empty()) {
            return result;
        }

        unordered_map<string, int> wordMap;
        for (const auto &str : strs) {
            vector<int> counts(26, 0); // 记录单词中每个单词出现的频次
            for (const auto &c : str) {
                ++counts[c - 'a'];
            }
            // 将频次拼接成字符串，作为 map 的 key
            string tmp = "";
            for (const auto &n : counts) {
                tmp += "#" + to_string(n);
            }

            if (wordMap.count(tmp) != 0) { // 在 map 中存在，即表示该类字母异位词已存在记结果组中
                int row = wordMap[tmp];
                result[row].push_back(str);
            } else {
                result.push_back(vector<string>(1, str));  // 保存一种新的字母异位词
                wordMap[tmp] = result.size() - 1; // 在 map 中记录行号
            }
        }

        return result;    
    }
};