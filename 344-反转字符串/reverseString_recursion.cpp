#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        reverse(s, 0, s.size() - 1);
    }
private:
    void reverse(vector<char> &s, int left, int right) {
        if (left >= right) {
            return;
        }

        swap(s[left], s[right]);
        reverse(s, left + 1, right - 1);
    }
};