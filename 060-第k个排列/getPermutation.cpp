#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string nums = "123456789";
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        --k;
        string result;
        for (int j = n; j >= 1; --j) {
            int tmp = k / factorial[j - 1];
            k %= factorial[j - 1];
            result.push_back(nums[tmp]);
            nums.erase(tmp, 1);
        }

        return result;
    }
};
