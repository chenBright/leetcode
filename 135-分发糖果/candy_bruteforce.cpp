#include <vector>
using namespace std;

// 蛮力法，超时
class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> candies(length, 1);
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < length; ++i) {
                if (i < length - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    flag = true;
                }
                // 更新
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    flag = true;
                }
            }
        }
        
        int result = 0;
        for (const auto &candy : candies) {
            result += candy;
        }

        return result;
    }
};
