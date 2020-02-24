#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        aux.reserve(length);
        for (int i = 1; i < length; i *= 2) { // 分组大小
            for (int low = 0; low < length - i; low += 2 * i) {
                // 归并的第一个子数组：[low, low + i - 1]
                // 归并的第二个子数组：[low + i, min(low + 2 * i - 1, length - 1)]
                merge(nums, low, low + i - 1, min(low + 2 * i - 1, length - 1));
            }
        }
        return nums;
    }
private:
    vector<int> aux;

    void merge(vector<int>& nums, int low, int mid, int high) {
        for (int k = low; k <= high; ++k) {
            aux[k] = nums[k];
        }

        int i = low;
        int j = mid + 1;
        for (int k = low; k <= high; ++k) {
            if (i > mid) {
                nums[k] = aux[j++];
            } else if (j > high) {
                nums[k] = aux[i++];
            } else if (aux[i] < aux[j]) {
                nums[k] = aux[i++];
            } else {
                nums[k] = aux[j++];
            }
        }
    }
};
