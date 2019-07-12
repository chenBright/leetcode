# 210-课程表 II

## 题目

leetcode：[210-课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)

## 拓扑排序

参考[207-课程表](../207-课程表/)，在此基础上添加保存结果的逻辑即可。

### BFS实现

该方法的时间复杂度为***O(n)***。

```c++
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
```

### DFS实现

该方法的时间复杂度为***O(n)***。

```c++
   vector<list<int> > adj(numCourses, list<int>()); // 邻接表
        // 有三种状态，
        // 0：初始值，完全没有访问过
        // 1：已经访问，但还能访问
        // -1：访问过了，但下次再访问，就会冲突
        vector<int> visited(numCourses, 0);
        
        for (const auto &nodes : prerequisites) {
            adj[nodes[1]].push_back(nodes[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(adj, visited, i, result)) {
                return vector<int>();
            }
        }

        vector<int> vResult(numCourses);
        for (int j = 0; j < numCourses; ++j) {
            vResult[j] = result.top();
            result.pop();
        }

        return vResult;
    }

private:
    bool canFinishDFS(vector<list<int> > &adj, vector<int> &visited, int node, stack<int> &result) {
        if (visited[node] == -1) {
            return false;
        }
        // 之所以三种状态，是因为如果此处判断是否等于 0，则全部结点都会放回 true
        if (visited[node] == 1) {
            return true;
        }

        visited[node] = -1;

        for (const auto &nextNode : adj[node]) {
            if (!canFinishDFS(adj, visited, nextNode, result)) {
                return false;
            }
        }

        // 该结点后面的结点不形成环路，则将该结点添加到栈中
        result.push(node);

        visited[node] = 1;

        return true;
    }
};
```

