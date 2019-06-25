#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        for (int i = 1; i <= n; ++i) {
            result.push_back(i + '0');
        }

        int j = 0;
        do {
            ++j;
            if (j == k) {
                break;
            }
        } while (next_permutation(result.begin(), result.end()));

        return result;
    }
};
