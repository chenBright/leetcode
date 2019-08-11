#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> sv;
        split(str, sv, ' ');

        if (pattern.size() != sv.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            if (find(sv.begin(), sv.end(), sv[i]) - sv.begin() != pattern.find(pattern[i])) {
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
