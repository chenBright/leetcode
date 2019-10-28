#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) {
            return 0;
        }

        int length = ratings.size();
        int result = 1;
        int previous = 1; // 连续递减序列的最大值
        int count = 0; // 连续递减序列的长度
        for (int i = 1; i < length; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                if (count > 0) {
                    // previous - count - count - 1 - ... - 1
                    result += count * (count + 1) / 2;
                    if (count >= previous) {
                        // 连续递减序列的最大值应该为 count，将加少了的补上
                        result += count - previous + 1;
                    }
                    previous = 1;
                    count = 0;
                }
                // ratings[i] <= ratings[i - 1]
                previous = (ratings[i] == ratings[i - 1]) ? 1 : previous + 1;
                result += previous;
            } else { // 统计连续递减序列的长度
                ++count;
            }
        }
        if (count > 0) {
            result += count * (count + 1) / 2;
            if (count >= previous) {
                result += count - previous + 1;
            }
        }

        return result;
    }
};
