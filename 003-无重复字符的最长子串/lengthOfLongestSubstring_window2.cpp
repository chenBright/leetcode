#include <string>
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.size();
        vector<int> indexs(256, -1); // 字符哈希表
        int start = 0;
        int end = 0;
        int maxLen = 0;

        while (start < strLen && end < strLen) {
            int index = indexs[s[end]]; // 字符索引
            // 如果字符未出现过，则扩大滑动窗口
            if (index == -1) {
                indexs[s[end]] = end;
                maxLen = max(maxLen, end - start + 1);
                // 移动滑动窗口右边界
                ++end;
            } else {
                // 移动滑动窗口左边界
                indexs[s[start++]] = -1;
            }
        }

        return maxLen;
    }
};