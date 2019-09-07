#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        char tmp;
        int length = s.size();
        for (int i = 0; i < length / 2; ++i) {
            swap(s[i], s[length - i - 1]);
        }
    }
};