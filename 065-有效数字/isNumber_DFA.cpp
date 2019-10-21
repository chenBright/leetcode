#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        int finals = 0b101101000;
        vector<vector<int> > transfer{{ 0, 1, 6, 2,-1},
                                      {-1,-1, 6, 2,-1},
                                      {-1,-1, 3,-1,-1},
                                      { 8,-1, 3,-1, 4},
                                      {-1, 7, 5,-1,-1},
                                      { 8,-1, 5,-1,-1},
                                      { 8,-1, 6, 3, 4},
                                      {-1,-1, 5,-1,-1},
                                      { 8,-1,-1,-1,-1}
                                    };
        vector<char> ss(s.begin(), s.end());
        for (int i = 0; i < ss.size(); ++i) {
            int id = make(ss[i]);
            if (id < 0) {
                return false;
            }
            state = transfer[state][id];
            if (state < 0) {
                return false;
            }
        }

        return (finals & (1 << state)) > 0;
    }

private:
    int make(int c) {
        switch (c) {
            case ' ':
                return 0;
            case '+':
            case '-': return 1;
            case '.': return 3;
            case 'e': return 4;
            default:
                if (c >= 48 && c <= 57) {
                    return 2;
                }
        }

        return -1;
    }
};
