#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());

        unordered_set<int> s;
        for (const auto &num : nums2) {
            if (binarySearch(nums1, num)) {
                s.insert(num);
            }
        }

        return vector<int>(s.begin(), s.end());
    }

private:
    bool binarySearch(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};