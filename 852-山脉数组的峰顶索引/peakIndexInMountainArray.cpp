#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if (A.empty()) {
            return -1;
        }

        int low = 0;
        int high = A.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] <= A[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};