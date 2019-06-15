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


        unordered_map<string, int> wordMap;
        for (const auto &str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());  // 排序

            if (wordMap.count(tmp) != 0) { // 在 map 中存在，即表示该类字母异位词已存在记结果组中
                int row = wordMap[tmp];
                result[row].push_back(str);
            } else {
                result.push_back(vector<string>(1, str)); // 保存一种新的字母异位词
                wordMap[tmp] = result.size() - 1; // 在 map 中记录行号
            }       
        }

        return result;    
    }
};