#include <vector>
#include <climits>
#include <stack>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> s;
        s.push(-1);
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                int peekIndex = s.top();
                s.pop();
                result = max(result, heights[peekIndex] * (i - s.top() - 1));
            }
            s.push(i);
        }

        while (s.top() != -1) {
            int peekIndex = s.top();
            s.pop();
            result = max(result, heights[peekIndex] * (static_cast<int>(heights.size()) - s.top() - 1));
        }

        return result;
    }
};
