#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length, 0);
        if (length == 0) {
            return result;
        }

        aux.reserve(length);
        vector<int> indexs(length); // 索引数组
        for (int i = 0; i < length; ++i) {
            indexs[i] = i;
        }

        mergeSort(nums, indexs, 0, static_cast<int>(nums.size()) - 1, result);

        return result;
    }

private:
    vector<int> aux;
    void mergeSort(vector<int>& nums, vector<int>& indexs, int low, int high, vector<int>& result) {
        if (low >= high) {
            return;
        }

        int mid = (low + high) / 2;
        mergeSort(nums, indexs, low, mid, result);
        mergeSort(nums, indexs, mid + 1, high, result);
        merge(nums, indexs, low, mid, high, result);
    }

    void merge(vector<int>& nums, vector<int>& indexs, int low, int mid, int high, vector<int>& result) {
        for (int k = low; k <= high; ++k) {
            aux[k] = indexs[k];
        }

        int i = low;
        int j = mid + 1;
        for (int k = low; k <= high; ++k) {
            if (i > mid) {
                indexs[k] = aux[j++];
            } else if (j > high) {
                indexs[k] = aux[i++];
                // 剩下的数比 [mid + 1, high] 对应的数都大，
                // 则逆序数为 high - mid
                result[indexs[k]] += high - mid;
            } else if (nums[aux[i]] <= nums[aux[j]]) {
                indexs[k] = aux[i++];
                // nums[aux[i]] 比 [mid + 1, j) 对应的数都大，
                // 则逆序数为 high - mid。
                result[indexs[k]] += j - mid - 1;
            } else {
                indexs[k] = aux[j++];
            }
        }
    }
};