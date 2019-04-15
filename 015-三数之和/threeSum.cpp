#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) { // 去重
                int j = i + 1;
                int k = nums.size() - 1;
                // 双指针
                while (j < k) {
                    int sum = nums[j] + nums[k];
                    if (sum == -nums[i]) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        res.push_back(temp);
                        ++j;
                        --k;
                        while (j < k && nums[j] == nums[j - 1]) { // 去重
                            ++j;
                        }
                        while (j <k && nums[k] == nums[k + 1]) { // 去重
                            --k;
                        }
                    } else if (sum < -nums[i]) {
                        ++j;
                    } else {
                        --k;
                    }
                }
            }
        }

        return res;
    }
};