#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str(n, '1');
        for (int i = 0; i < n; ++i) {
            str[i] = i + '1';
        }

        for (int j = 0; j < k - 1; ++j) {
            next_permutation(str.begin(), str.end());
        }

        return str;
    }
};
