#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        int low = 0;
        int high = len - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int papers = len - mid;
            if (papers == citations[mid]) {
                return papers;
            } else if (papers < citations[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // 结束循环后，low、high 肯定与目标值相邻或者重合。
        // 根据实际情况，决定结果。
        return len - low;
    }
};
