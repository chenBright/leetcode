#include <vector>
using namespace std;

// 归并排序
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> temp(prices.size());
        int profit = maxProfit(prices, 0, prices.size() - 1, temp);
        if (profit < 0) {
            profit = 0;
        }

        return profit;
    }

private:
    int maxProfit(vector<int> &prices, int low, int high, vector<int> &temp) {
        if (low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;
        int leftProfit = maxProfit(prices, low, mid, temp); // 左半边的最大利润
        int rightProfit = maxProfit(prices, mid + 1, high, temp); // 右半边的最大利润
        int holeProfit = prices[high] - prices[low]; // 右半边最大值 - 左半边最小值

        int profit = leftProfit > rightProfit ? leftProfit : rightProfit;
        if (holeProfit > profit) {
            profit = holeProfit;
        }

        int left = low;
        int right = mid + 1;
        int tempIndex = low;
        // 归并
        while (left <= mid && right <= high) {
            if (prices[left] <= prices[right]) {
                temp[tempIndex++] = prices[left++];
            } else {
                temp[tempIndex++] = prices[right++];
            }
        }

        while (left <= mid) {
            temp[tempIndex++] = prices[left++];
        }
        while (right <= high) {
            temp[tempIndex++] = prices[right++];
        }

        for (int i = low; i <= high; ++i) {
            prices[i] = temp[i];
        }

        return profit;
    }
};