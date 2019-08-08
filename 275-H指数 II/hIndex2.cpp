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
            // 本来是寻找最后一个符合 papers >= citations[mid] 的元素
            // 改成 papers > citations[mid]，可以理解为：
            // 当前 mid 可能不是最后一个符合条件的元素，所以向后移动一个位置继续查找。
            // 最后，结束循环后，low、high 肯定与目标值相邻或者重合。
            // 根据实际情况，决定结果。
            if (papers > citations[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return len - low;
    }
};
