#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        // 在[1 ... n]中搜索重复的数字
        int low = 1;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (const auto &num : nums) {
                if (num <= mid) {
                    ++count;
                }
            }

            if (count > mid) { // 重复数字在前面部分，包括 mid（也有可能是 mid）
                high = mid;
            } else { // 重复数字在后面部分
                low = mid + 1;
            }
        }

        return high;
    }
};
