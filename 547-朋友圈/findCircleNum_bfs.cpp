#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
        if (M.empty()) {
            return 0;
        }

        int result = 0;
        int length = M.size();
        vector<int> visited(length, 0);
        for (int i = 0; i < length; ++i) {
            if (visited[i] == 0) {
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int index = q.front();
                    q.pop();
                    if (visited[index] == 1) {
                        continue;
                    }

                    visited[index] = 1;
                    for (int j = 0; j < length; ++j) {
                        if (M[index][j] == 1 && visited[j] == 0) {
                            q.push(j);
                        }
                    }
                }

                ++result;
            }
        }

        return result;
    }
};
