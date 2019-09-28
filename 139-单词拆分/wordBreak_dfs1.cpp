#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

// 深度优先搜索
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int strLen = s.size();
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }

        for (auto word : wordDict) {
            wordLenSet.insert(word.size());
            wordSet.insert(word);
        }

        return dfs(s, 0);
    }

private:
    set<int> wordLenSet; // 用于储存wordDict中单词的长度
    set<string> wordSet; // 记录单词出现次数

    bool dfs(string &s, int start) {
        int strLen = s.size();
        if (start >= strLen) {
            return true;
        }

        for (auto it = wordLenSet.rbegin(); it != wordLenSet.rend(); ++it) { // set默认从大到小排序，先从短子串开始搜索
            string subStr = s.substr(start, *it); // 以start为起始，获取*it长的子串
            if (wordSet.find(subStr) != wordSet.end() && dfs(s, start + *it)) {
                return true;
            }
        }

        return false;
    }
};