#include <string>
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.size();
        if (strLen <= 1) {
            return strLen;
        }        
        // 只少两个字符
        vector<int> indexs(256, -1); // 字符哈希表
        int start = 0;
        int end = 1;
        int maxLen = 1;
        indexs[s[start]] = start;

        while (start < strLen && end < strLen) {
            int index = indexs[s[end]]; // 字符索引
            // 如果字符出现过，则计算最大长度，移动滑动窗口左边界
            if (index != -1) {
                while (start <= index) {
                    indexs[s[start]] = -1;
                    ++start;
                }
            }
            maxLen = max(maxLen, end - start);
            indexs[s[end]] = end;
            // 移动滑动窗口右边界
            ++end;
        }

        // 一直遍历到字符串末尾，都没出现重复字符，则还需要计算一次最大长度
        return max(maxLen, end - start);
    }
};