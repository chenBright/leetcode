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
