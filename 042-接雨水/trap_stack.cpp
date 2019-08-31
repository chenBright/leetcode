#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        int current = 0;
        stack<int> s;

        while (current < height.size()) {
            // 如果栈不空并且当前指向的高度大于栈顶高度就一直循环
            while (!s.empty() && height[current] > height[s.top()]) {
                int h = height[s.top()];
                s.pop();
                if (s.empty()) {
                    break;
                }
                int distance = current - s.top() - 1; // 两堵墙之前的距离
                int minHeight = min(height[s.top()], height[current]);
                sum += distance * (minHeight - h);
            }
            s.push(current);
            ++current;
        }

        return sum;
    }
};