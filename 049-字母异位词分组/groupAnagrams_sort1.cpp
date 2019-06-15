#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > result;
        if (strs.empty()) {
            return result;
        }

        // 保存单词内字符排序好的字符串
        vector<string> tmpStrs(strs);
        for (auto &str : tmpStrs) {
            sort(str.begin(), str.end());  // 排序          
        }

        unordered_map<string, int> wordMap; // 排序字符串 -> 行号
        for (int i = 0; i < tmpStrs.size(); ++i) {
            if (wordMap.count(tmpStrs[i]) != 0) { // 在 map 中存在，即表示该类字母异位词已存在记结果组中
                int row = wordMap[tmpStrs[i]];
                result[row].push_back(strs[i]);
            } else {
                result.push_back(vector<string>(1, strs[i])); // 保存一种新的字母异位词
                wordMap[tmpStrs[i]] = result.size() - 1; // 在 map 中记录行号
            }
        }

        return result;    
    }
};