# 547-朋友圈

## 题目

leetcode：[547-朋友圈](https://leetcode-cn.com/problems/friend-circles/)

## DFS

```c++
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
```

## BFS

```c++
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
```

## 并查集

参考[Union-Find 算法详解](https://leetcode-cn.com/problems/friend-circles/solution/union-find-suan-fa-xiang-jie-by-labuladong/)。

```c++
class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
        if (M.empty()) {
            return 0;
        }

        int N = M.size();
        int count = N;              // 森林中树的数量
        vector<int> parents(N, -1); // 根结点的父结点为 -1
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (M[i][j] == 1 && i != j) {
                    unionTree(parents, i, j, count);
                }
            }
        }

        return count;
    }
private:
    int find(vector<int>& parents, int index) {
        // 查找根结点
        while (parents[index] != -1) {
            index = parents[index];
        }
        return index;
    }

    void unionTree(vector<int>& parents, int i, int j, int& count) {
        int iParent = find(parents, i);
        int jParent = find(parents, j);
        if (iParent != jParent) {
            // 合并两棵树
            parents[iParent] = jParent;
            // 合并导致少了一棵树
            --count;
        }
    }
};
```

### 平衡性优化、压缩路径

```c++
class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
        if (M.empty()) {
            return 0;
        }

        int N = M.size();
        int count = N;              // 森林中树的数量
        vector<int> parents(N, -1); // 根结点的父结点为 -1
        vector<int> size(N, 1);     // 树的结点数（用于平衡合并时树的高度）
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (M[i][j] == 1 && i != j) {
                    unionTree(parents, i, j, count, size);
                }
            }
        }

        return count;
    }
private:
    int find(vector<int>& parents, int index) {
        // 查找根结点
        while (parents[index] != -1) {
            if (parents[parents[index]] != -1) {
                // 压缩路径
                // 修改 index 结点的父结点为 原 index 父结点的父结点，
                // 修改后， index 和 parents[index] 为兄弟结点。
                parents[index] = parents[parents[index]];
            }
            index = parents[index];
        }
        return index;
    }

    void unionTree(vector<int>& parents, int i, int j, int& count, vector<int>& size) {
        int iParent = find(parents, i);
        int jParent = find(parents, j);
        if (iParent == jParent) {
            return;
        }

        // 将小的树连接到大的树上
        if (size[iParent] < size[jParent]) {
            // 合并两棵树
            parents[iParent] = jParent;
            size[jParent] += size[iParent];
        } else {
            // 合并两棵树
            parents[jParent] = iParent;
            // 合并导致少了一棵树
            size[iParent] += size[jParent];
        }
        --count;
    }
};
```
