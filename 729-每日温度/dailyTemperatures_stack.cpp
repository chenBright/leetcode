#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) {
            return vector<int>();
        }

        int length = T.size();
        vector<int> result(length, 0);
        stack<int> s;

        for (int i = 0; i < T.size(); ++i) {
            while (!s.empty() && T[s.top()] < T[i]) {
                int top = s.top();
                s.pop();
                result[top] = i - top;
            }
            s.push(i);
        }

        return result;
    }
};
