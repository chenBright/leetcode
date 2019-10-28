#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> candies(length, 1);

        // 更新与左边孩子的关系
        for (int i = 1; i < length; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int j = length - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                // 取最大值才满足条件
                candies[j] = max(candies[j], candies[j + 1] + 1);
            }
        }

        int result = 0;
        for (const auto &candy : candies) {
            result += candy;
        }

        return result;
    }
};
