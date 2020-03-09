#include <string>
#include <algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        if (next_permutation(str.begin(), str.end())) {
            // 小心整型溢出
            long result = stol(str);

            return result > INT_MAX ? -1 : result;
        }

        // 找不到比 n 大的，位一样的整型数

        return -1;
    }
};