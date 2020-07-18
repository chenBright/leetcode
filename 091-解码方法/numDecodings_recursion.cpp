#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        unordered_map<int, int> m;

        return numDecodings(s, 0, m);
    }
private:
    int numDecodings(string& s, int i, unordered_map<int, int>& m) {
        if (m.count(i)) {
            return m[i];
        }

        int length = s.size();
        if (i == length) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        if (i + 1 == length) {
            return 1;
        }

        m[i] = numDecodings(s, i + 1, m);
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
            m[i] += numDecodings(s, i + 2, m);
        }

        return m[i];
    }
};