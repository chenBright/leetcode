#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        // 构建堆
        for (int i = (length - 1) / 2; i >= 0; --i) {
            sink(nums, i, length);
        }

        // 排序
        for (int j = length - 1; j > 0; --j) {
            // 将当前最大的结点放到最后面。
            swap(nums[j], nums[0]);
            // 重新构建堆
            sink(nums, 0, j);
        }

        return nums;
    }

private:
    // 上浮
    void swim(vector<int>& nums, int k) {
            while (k > 0 && nums[(k - 1) / 2] < nums[k]) {
            swap(nums[(k - 1) / 2], nums[k]);
            k = (k - 1) / 2;
        }
    }
    // 下沉，下沉到较大的结点中。
    void sink(vector<int>& nums, int k, int length) {
        while (2 * k + 1 < length) {
            int c1 = 2 * k + 1; // 左结点
            int c2 = 2 * k + 2; // 右结点
            int c = (c2 < length && nums[c2] > nums[c1]) ? c2 : c1; // c是值最大的孩子节点

            if (nums[k] >= nums[c]) {
                break;
            }

            swap(nums[k], nums[c]);
            k = c;
        }
    }
};
