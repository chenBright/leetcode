#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> m(26, 0);
        for (const auto& c : tasks) {
            ++m[c - 'A'];
        }

        priority_queue<int> q; // 大根堆
        for (const auto& n : m) {
            if (n > 0) {
                q.push(n);
            }
        }

        int time = 0;
        while (!q.empty()) {
            int i = 0;
            vector<int> tmp;
            while (i <= n) {
                if (!q.empty()) {
                    if (q.top() > 1) {
                        tmp.push_back(q.top() - 1);
                    }
                    q.pop();
                }
                ++time;
                if (q.empty() && tmp.empty()) {
                    break;
                }
                ++i;
            }
            for (const auto& t : tmp) {
                q.push(t);
            }
        }

        return time;
    }
};
