#include <map>
using namespace std;

class Solution {
public:
    Solution() {
        m[0] = 1;
    }

    int numTrees(int n) {
        // 如果已经保存结果，直接返回
        if (m.count(n)) {
            return m[n];
        }

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            // 结点i为根结点时，二叉搜索树的个数
            int left = numTrees(i - 1);
            m[i - 1] = left;

            int right = numTrees(n - i);
            m[n - i] = right;
            
            res +=  left * right;
        }
        m[n] = res;

        return res;
    }

private:
    map<int, int> m; // 保存计算结果
};