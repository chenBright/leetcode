#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (const auto& p : pushed) {
            s.push(p);
            while (!s.empty() && j < popped.size() && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }

        return s.empty();
    }
};
