#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 基数排序
class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int exp = 1; // 1, 10, 100, 1000 ...
        int radix = 10; // 10 进制

        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> aux(nums.size()); // 暂存中间排序结果
        while (maxNum / exp > 0) {
            vector<int> count(radix, 0);

            // 对于外循环，依次取个位、十位、百位 ...
            for (const auto& num : nums) {
                ++count[num / exp % 10]; // 统计个数
            }

            // 此时，count[i] 表示 小于等于 i 的元素的个数，将来用来表示 nums[i] 的下标，从而达到排序的目的。
            partial_sum(count.begin(), count.end(), count.begin());

            for (int i = nums.size() - 1; i >= 0; --i) {
                aux[--count[nums[i] / exp % 10]] = nums[i]; // 排序
            }

            for (int i = 0; i < nums.size(); ++i) {
                nums[i] = aux[i];
            }

            exp *= 10;
        }

        int maxGap = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            maxGap = max(maxGap, nums[i + 1] - nums[i]);
        }

        return maxGap;
    }
};
