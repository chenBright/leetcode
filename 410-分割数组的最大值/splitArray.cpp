#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxNum = 0;
        long sum = 0;
        // 计算「子数组各自的和的最大值」的上下界
        for (const auto& num : nums) {
            maxNum = max(maxNum, num);
            sum += num;
        }

        // 使用「二分查找」确定一个恰当的「子数组各自的和的最大值」，
        // 使得它对应的「子数组的分割数」恰好等于 m
        long left = maxNum;
        long right = sum;
        while (left < right) {
            long mid = left + (right - left) / 2;
            int count = split(nums, mid);
            if (count > m) {
                // 如果分割数太多，说明「子数组各自的和的最大值」太小，此时需要将「子数组各自的和的最大值」调大
                // 下一轮搜索的区间是 [mid + 1, right]
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
private:
    int split(vector<int> nums, long sum) {
        long maxIntervalSum = 0; // 当前的区间和
        int count = 1; // 至少是一个分割
        for (const auto& num : nums) {
            // 尝试加上当前遍历的这个数，如果加上去超过了「子数组各自的和的最大值」，就不加这个数，另起炉灶
            if (maxIntervalSum + num > sum) {
                maxIntervalSum = 0;
                ++count;
            }
            maxIntervalSum += num;
        }

        return count;
    }
};