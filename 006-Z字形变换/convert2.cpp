#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> rows(min(numRows, static_cast<int>(s.size())));
        int curRow = 0;
        bool toDown = false;

        for (const char &c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                toDown = !toDown;
            }
            curRow += toDown ? 1 : -1;
        }

        string result;
        for (const string &row : rows) {
            result += row;
        }

        return result;
    }
};
