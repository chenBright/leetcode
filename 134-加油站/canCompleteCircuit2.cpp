#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int toatalTank = 0; // 总油量
        int maxTank = 0; // 剩余油量的最大值
        int index = 0; // 起点
        for (int i = gas.size() - 1; i >= 0; --i) {
            toatalTank += gas[i] - cost[i];
            if (toatalTank > maxTank) {
                index = i;
                maxTank = toatalTank;
            }
        }

        return toatalTank < 0 ? -1 : index;
    }
};