#include <string>
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLength = s.size();
        vector<int> hash(256, 0); // 字符哈希表
        int start = 0;
        int end = 0;
        int maxLength = 0;

        while (start < strLength && end < strLength) {
            // 如果字符未出现过，则扩大滑动窗口
            if (hash[s[end]] == 0) {
                hash[s[end]] = 1;
                maxLength = max(maxLength, end - start + 1);
                // 移动滑动窗口右边界
                ++end;
            } else {
                // 移动滑动窗口左边界
                hash[s[start++]] = 0;
            }
        }

        return maxLength;
    }
};