#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, vector<string> > memory; // <字符串, 字符串的才分结果数组>
        return dfs(s, wordDict, memory);
    }
private:
    vector<string> dfs(string s, vector<string> &wordDict, unordered_map<string, vector<string> > &memory) {
        if (memory.count(s)) {
            return memory[s];
        }

        if (s.empty()) {
            return {""};
        }

        vector<string> result;
        for (const auto &word : wordDict) {
            int wordSize = word.size();
            string tmp = s.substr(0, wordSize);
            if (tmp != word) {
                continue;
            }
            vector<string> tmpResult = dfs(s.substr(wordSize), wordDict, memory);
            for (const auto &str : tmpResult) {
                result.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        memory[s] = result;

        return result;
    }
};
