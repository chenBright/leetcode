#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        int newLen = 0; // 新数组长度
        int pIndex = 0; //遍历指针
        while (newLen < len && pIndex < len) {
            if (nums[pIndex] != val) {
                nums[newLen] = nums[pIndex];
                ++newLen;
            }
            ++pIndex;
        }

        return newLen;
    }
};