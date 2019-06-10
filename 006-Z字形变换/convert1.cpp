#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string result;
        int n = s.size();
        int step = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < n; j += step) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + step - i < n) {
                    result += s[j + step - i];
                }
            }
        }

        return result;
    }
};
