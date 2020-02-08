#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > result;
        int length = nums.size();
        sort(nums.begin(), nums.end());

        // 不需要完全遍历数组，主需要遍历到 nums[length - 4]即可。
        // 因为结果为三元组，nums[length - 3]、nums[length - 2]、nums[length - 1]
        // 没有足够的元素与之组成四元组，所以不需要遍历它们。
        for (int i = 0; i <= length - 4; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 去重
                continue;
            }
            // 不需要完全遍历数组，主需要遍历到 nums[length - 3]即可。
            // 因为结果为三元组，nums[length - 2]、nums[length - 1]
            // 没有足够的元素与之组成三元组，所以不需要遍历它们。
            for (int j = i + 1; j <= length - 3; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 去重
                    continue;
                }
                int m = j + 1;
                int n =length - 1;
                while (m < n) {
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[m], nums[n]});
                        ++m;
                        --n;
                        while (m < n && nums[m] == nums[m - 1]) { // 去重
                            ++m;
                        }
                        while (m < n && nums[n] == nums[n + 1]) { // 去重
                            --n;
                        }
                    } else if (sum < target) {
                        ++m;
                    } else {
                        --n;
                    }
                }
            }
        }
        return result;
    }
};