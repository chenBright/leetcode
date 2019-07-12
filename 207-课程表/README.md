# 207-课程表

## 题目

leetcode：[207-课程表](https://leetcode-cn.com/problems/course-schedule/)

## 拓扑排序

该题的核心是判断给定有向图是否有环路。

### BFS实现

参考[博客](https://songlee24.github.io/2015/05/07/topological-sorting/)，使用BFS实现拓扑排序。

该方法的时间复杂度为***O(n)***，空间复杂度为***O(n)***。

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites) {
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
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ++count;
            for (auto it = adj[node].begin(); it != adj[node].end(); ++it) {
                --indegrees[*it];
                if (indegrees[*it] == 0) {
                    q.push(*it);
                }
            }
        }

        return count == numCourses;
    }
};
```

### DFS实现

参考[博客 解法二](https://www.cnblogs.com/grandyang/p/4484571.html)，使用DFS实现拓扑排序。

该方法的时间复杂度为***O(n)***，空间复杂度为***O(n)***。

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites) {
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
            if (!canFinishDFS(adj, visited, i)) {
                return false;
            }
        }

        return true;
    }

private:
    bool canFinishDFS(vector<list<int> > &adj, vector<int> &visited, int node) {
        if (visited[node] == -1) {
            return false;
        }
        // 之所以三种状态，是因为如果此处判断是否等于 0，则全部结点都会放回 true
        if (visited[node] == 1) {
            return true;
        }

        visited[node] = -1;

        for (const auto &nextNode : adj[node]) {
            if (!canFinishDFS(adj, visited, nextNode)) {
                return false;
            }
        }

        visited[node] = 1;

        return true;
    }
};
```

