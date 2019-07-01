#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int toatalTank = 0; // 总油量
        int currentTank = 0; // 当前油量
        int index = 0; // 起点
        for (int i = 0; i < gas.size(); ++i) {
            int remain = gas[i] - cost[i];
            toatalTank += remain;
            currentTank += remain;
            if (currentTank < 0) {
                index = i + 1;
                currentTank = 0;
            }
        }

        return toatalTank < 0 ? -1 : index;
    }
};