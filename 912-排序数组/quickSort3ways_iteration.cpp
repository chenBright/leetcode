#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        queue<pair<int, int> > q;
        q.push(make_pair(low, high));
        while (!q.empty()) {
            auto region = q.front();
            q.pop();

            auto indexs = paritition(nums, region.first, region.second);
            // 分区长度大于 1，则将入队列中继续排序。
            if (region.first < indexs.first) {
                q.push(make_pair(region.first, indexs.first));
            }
            if (indexs.second < region.second) {
                q.push(make_pair(indexs.second, region.second));
            }
        }
    }

    pair<int, int> paritition(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return make_pair(left, left);
        }

        int i = left;
        int j = right;
        int k = i + 1;
        while (k <= j) {
            // 小于 pivot 的范围：[low, i - 1]
            // 等于 pivot 的范围：[i, k]
            // 大于 pivot 的范围：[j + 1, high]
            if (nums[k] < nums[i]) {
                swap(nums[k++], nums[i++]);
            } else if (nums[k] > nums[i]) {
                // 因为 nums[j] 未比较，所以 k 不变。下一循环时，再比较。
                swap(nums[k], nums[j--]);
            } else {
                ++k;
            }
        }

        return make_pair(i - 1, j + 1);
    }
};
