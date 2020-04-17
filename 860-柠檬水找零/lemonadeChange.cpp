#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coin5 = 0;
        int coin10 = 0;
        for (const auto& bill : bills) {
            if (bill == 5) {
                ++coin5;
            } else if (bill == 10) {
                if (coin5 < 1) {
                    return false;
                }
                ++coin10;
                --coin5;
            } else {
                if (coin10 >= 1 && coin5 >= 1) {
                    --coin10;
                    --coin5;
                } else if (coin5 >= 3) {
                    coin5 -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};