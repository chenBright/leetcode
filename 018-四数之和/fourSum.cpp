#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 去重
                continue;
            }
            for (int j = i + 1; j < len; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 去重
                    continue;
                }
                int m = j + 1;
                int n =len - 1;
                while (m < n) {
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[m], nums[n]};
                        res.push_back(temp);
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
        return res;
    }
};