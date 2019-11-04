#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> m(26, 0);
        for (const auto& c : tasks) {
            ++m[c - 'A'];
        }

        sort(m.begin(), m.end());
        int time = 0;
        while (m[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (m[25] == 0) {
                    break;
                }
                if (i < 26 && m[25 - i] > 0) {
                    --m[25 - i];
                }
                ++time;
                ++i;
            }
            sort(m.begin(), m.end());
        }

        return time;
    }
};
