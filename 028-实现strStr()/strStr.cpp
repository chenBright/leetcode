#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        int needleSize = needle.size();
        int haystackSize = haystack.size();
        if (needleSize > haystackSize) {
            return -1;
        }

        int i = 0;
        int j = 0;
        for (; i < haystackSize; ++i) {
            if (j == needleSize) {
                return i - needleSize;
            }

            if (haystack[i] == needle[j]) {
                ++j;
            } else {
                i -= j;
                j = 0;
            }
        }

        if (j == needleSize) {
            return i - needleSize;
        }

        return -1;
    }
};