#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        aux.reserve(nums.size());
        mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    vector<int> aux;
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;
        mergeSort(nums, low ,mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

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