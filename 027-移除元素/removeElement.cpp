#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int newLen = 0; // 新数组长度
        int pIndex = 0; //遍历指针
        while (pIndex < nums.size()) {
            if (nums[pIndex] != val) {
                nums[newLen++] = nums[pIndex];
            }
            ++pIndex;
        }

        return newLen;
    }
};
