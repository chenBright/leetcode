#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int left = length;
        int right = 0;
        
        stack<int> leftStack;
        for (int i = 0; i < length; ++i) {
            while (!leftStack.empty() &&  nums[leftStack.top()]> nums[i]) {
                left = min(left, leftStack.top());
                leftStack.pop();
            }
            leftStack.push(i);
        }

        stack<int> rightStack;
        for (int j = length - 1; j >= 0; --j) {
            while (!rightStack.empty() && nums[rightStack.top()] < nums[j]) {
                right = max(right, rightStack.top());
                rightStack.pop();
            }
            rightStack.push(j);
        }

        return right >= left ? right - left + 1 : 0;
    }
};
