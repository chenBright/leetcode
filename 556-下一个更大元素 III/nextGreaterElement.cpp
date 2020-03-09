#include <string>
#include<climits>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        int length = str.size();
        int i = length - 2;
        while (i >= 0 && str[i] >= str[i + 1]) {
            --i;
        }

        if (i < 0) {
            return -1;
        }

        for (int j = length - 1; j >= 0; --j) {
            if (str[j] > str[i]) {
                swap(str[j], str[i]);
                sort(str.begin() + i + 1, str.end());
                break;
            }
        }

        // 小心整型溢出
        long result = stol(str);

        return result > INT_MAX ? -1 : result;
    }
};