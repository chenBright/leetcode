#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 深度优先搜索
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memory(s.size(), -1); // -1 表示没记录，0 表示 false， 1 表示 true。

        return dfs(s, wordSet, 0, memory);
    }

private:
    bool dfs(string &s, unordered_set<string> &wordSet, int start, vector<int> &memory) {
        int strLen = s.size();
        if (start >= strLen) {
            return true;
        }
        if (memory[start] != -1) {
            return memory[start] == 1;
        }

        for (int i = start + 1; i <= strLen; ++i) {
            if (wordSet.count(s.substr(start, i - start)) && dfs(s, wordSet, i, memory)) {
                memory[start] = 1;
                return true;
            }
        }
        memory[start] = 0;

        return false;
    }
};