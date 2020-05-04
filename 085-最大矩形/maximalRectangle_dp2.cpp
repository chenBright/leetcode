#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int maxArea = 0;
        // dp[i] 表示第 i 列，从上到下，包含 1 的连续序列的长度
        vector<int> dp(matrix[0].size());

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            maxArea = max(maxArea, helper(dp));
        }

        return maxArea;
    }

private:
    int helper(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int maxArea = 0;
        int length = heights.size();
        for (int i = 0; i < length; ++i) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                int peek = s.top();
                s.pop();
                // 中间空出来的索引，表示两边都高。
                // 计算 （s.top(), i) 的面积，高为 heights[peek]，
                // 因为栈顶到栈底，高度递减。
                maxArea = max(maxArea, heights[peek] * (i - s.top() - 1));
            }
            s.push(i);
        }

        // 因为栈顶到栈底，高度递减，所以再从右到左计算
        while(s.top() != -1) {
            int peek = s.top();
            s.pop();
            maxArea = max(maxArea, heights[peek] * (length - s.top() - 1));
        }

        return maxArea;

    }
};