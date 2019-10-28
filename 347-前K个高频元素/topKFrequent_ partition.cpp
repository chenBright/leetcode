#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计数字出现的次数
        unordered_map<int, int> m; // <数字， 次数>
        for (const auto& n : nums) {
            ++m[n];
        }

        vector<pair<int, int> > countAndNum(m.begin(), m.end()); // <次数，数字>
        findKth(countAndNum, 0, countAndNum.size() - 1, k - 1);

        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = countAndNum[i].first;
        }

        return result;
    }

private:
    void findKth(vector<pair<int, int> >& countAndNum, int low, int high, int k) {
        int index = partition(countAndNum, low, high);

        if (index < k) {
            findKth(countAndNum, index + 1, high, k);
        } else if (index > k) {
            findKth(countAndNum, low, index - 1, k);
        }
    }

    int partition(vector<pair<int, int> >& countAndNum, int low, int high) {
        auto pivot = countAndNum[low];  // 基准元素
        while (low < high) {
            // 因为 low 位置的元素用于基准元素， low 位置先空出来，所以要先从后面开始找。

            // 从后面开始找，找到第一个不大于基准元素的元素
            while (low < high && countAndNum[high].second < pivot.second) {
                --high;
            }
            // 将其放到空出来的位置，此时 high 位置空出来了。
            countAndNum[low] = countAndNum[high]; 

            while (low < high && countAndNum[low].second >= pivot.second) {
                ++low;
            }
            // 将其放到空出来的位置，此时 low 位置空出来了。
            countAndNum[high] = countAndNum[low]; 
        }
        countAndNum[low] = pivot;
        return low; // 最后的位置 i == j 就是基准元素的最终位置
    }
};
