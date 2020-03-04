#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /**
         * 对于任意一天考虑四个变量:
         * fstBuy: 在该天第一次买入股票可获得的最大收益
         * fstSell: 在该天第一次卖出股票可获得的最大收益
         * secBuy: 在该天第二次买入股票可获得的最大收益
         * secSell: 在该天第二次卖出股票可获得的最大收益
         * 分别对四个变量进行相应的更新, 最后secSell就是最大
         * 收益值(secSell >= fstSell)
         */
        int fstBuy = INT_MIN;
        int fstSell = 0;
        int secBuy =INT_MIN;
        int secSell = 0;
        for(int price : prices) {
            fstBuy = max(fstBuy, -price);
            fstSell = max(fstSell, fstBuy + price);
            secBuy = max(secBuy, fstSell - price);
            secSell = max(secSell, secBuy + price);
        }

        return secSell;
    }
};
