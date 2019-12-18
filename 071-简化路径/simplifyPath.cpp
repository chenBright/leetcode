#include <string>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        split(path, dirs, '/');

        string result = "";
        for (const auto& d : dirs) {
            result += "/" + d;
        }

        return result.empty() ? "/" : result;
    }

private:
    void split(const std::string& str, std::vector<std::string>& tokens, const char delim = ' ') {
        std::istringstream iss(str);
        std::string tmp;
        while (std::getline(iss, tmp, delim)) {
            if (!tokens.empty() && tmp == "..") {
                tokens.pop_back();
            } else if (!tmp.empty() && tmp != "." && tmp != "..") {
                tokens.emplace_back(std::move(tmp));
            }
        }
    }
};