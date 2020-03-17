#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
        if (M.empty()) {
            return 0;
        }

        int length = M.size();
        vector<int> visited(length, 0);
        int result = 0;
        for (int i = 0; i < length; ++i) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                ++result;
            }
        }

        return result;
    }
private:
    void  dfs(vector<vector<int> >& M, vector<int>& visited, int index) {
        for (int i = 0; i < visited.size(); ++i) {
            if (M[index][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                dfs(M, visited, i);
            }
        }
    }
};