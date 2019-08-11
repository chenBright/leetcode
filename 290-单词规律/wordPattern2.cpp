#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2s;
        unordered_map<string, int> s2p;
        vector<string> sv;
        split(str, sv, ' ');

        if (pattern.size() != sv.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string word = sv[i];
            if (p2s.count(c) != 0 && s2p.count(word) != 0) {
                if (p2s[c] != s2p[word]) {
                    return false;
                }
            } else if (p2s.count(c) == 0 && s2p.count(word) == 0) {
                p2s[c] = i + 1;
                s2p[word] = i + 1;
            } else {
                return false;
            }
        }

        return true;
    }
private:
    // 分割字符串
    void split(const string &str, vector<string> &sv, const char delim = ' ') {
        istringstream in(str);
        string tmp;
        while (getline(in, tmp, delim)) {
            sv.push_back(std::move(tmp));
        }
    }
};
