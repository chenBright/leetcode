#include <vector>
using namespace std;

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
