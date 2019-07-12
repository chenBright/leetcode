#include <vector>
#include <list>
#include <queue>
using namespace std;

// BFS 实现的拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites) {
        vector<int> result;
        vector<list<int> > adj(numCourses, list<int>()); // 邻接表
        vector<int> indegrees(numCourses, 0); // 各结点的入度
        queue<int> q; // 入度为 0 的结点队列
        
        for (const auto &nodes : prerequisites) {
            adj[nodes[1]].push_back(nodes[0]);
            ++indegrees[nodes[0]];
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // 成功访问的结点的个数
        int lastNode = -1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);
            ++count;
            for (auto it = adj[node].begin(); it != adj[node].end(); ++it) {
                --indegrees[*it];
                if (indegrees[*it] == 0) {
                    q.push(*it);
                }
            }
        }

        return count == numCourses ? result : vector<int>();
    }
};