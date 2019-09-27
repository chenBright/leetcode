#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> words;
        vector<string> result;
        dfs(s, wordDict, words, result);

        return result;
    }
private:
    void dfs(string s, vector<string> &wordDict, vector<string> &words, vector<string> &result) {
        if (s.empty()) {
            string tmpResult;
            for (const auto &word : words) {
                tmpResult += word + " ";
            }
            tmpResult.pop_back(); // 删除最后多余的空格
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            string tmp = s.substr(0, i + 1);
            if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()) {
                words.push_back(tmp);
                dfs(s.substr(i + 1), wordDict, words, result);
                words.pop_back();
            }
        }
    }
};
