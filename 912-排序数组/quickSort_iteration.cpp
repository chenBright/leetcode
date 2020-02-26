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
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        queue<pair<int, int> > q; // 保存需要排序的区域，<left, right>
        q.push(make_pair(left, right));
        while (!q.empty()) {
            auto region = q.front();
            q.pop();

            int index = paritition(nums, region.first, region.second);
            // 分区长度大于 1，则将入队列中继续排序。
            if (region.first < index - 1) {
                q.push(make_pair(region.first, index - 1));
            }
            if (index + 1 < region.second) {
                q.push(make_pair(index + 1, region.second));
            }
        }
    }

    int paritition(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return left;
        }

        int pivot = nums[left];
        while (left < right) {
            // 因为 left 空出来了，所以先从后面开始。
            // 找到小于等于 pivot 的元素
            while (left < right && nums[right] > pivot) {
                --right;
            }
            if (left == right) {
                break;
            }
            nums[left++] = nums[right];

            // 找到大于 pivot 的元素
            while (left < right && nums[left] <= pivot) {
                ++left;
            }
            if (left == right) {
                break;
            }
            nums[right--] = nums[left];
        }
        nums[left] = pivot;

        return left;
    }
};