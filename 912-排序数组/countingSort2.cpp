#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int bucketsNum = high - low + 1;
        vector<int> buckets(bucketsNum, 0);
        for (const auto& num : nums) {
            ++buckets[num - low];
        }

        int j = 0;
        for (int i = 0; i < bucketsNum; ++i) {
            while (buckets[i]-- > 0) {
                nums[j++] = i + low;
            }
        }

        return nums;
    }
};
