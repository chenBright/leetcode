#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int pre1 = 0;
        int pre2 = 0;
        /**
         * cost数组每个数字的含义是，当从台阶i离开时，需要花费cost[i]
         * 注意是离开时才有花费，进入台阶i是不花费的，所以只有一个台阶是花费为0(不走这个台阶)，两个台阶时花费为较小的那个台阶(从较小花费的台阶离开)
         * 因此题目的要求实际上是，跨越数组的所有台阶的最小花费
         * 循环从2开始，截止到cost.size()，使得循环结束后，pre2为跨越最后一个台阶的最小花费
         */
        for (int i = 2; i <= cost.size(); ++i) {
            int cur = min(pre1 + cost[i - 2], pre2 + cost[i - 1]);
            pre1 = pre2;
            pre2 = cur;
        }

        return pre2;
    }
};