#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        // 分配桶的长度和个数是桶排序的关键
        // 在 n 个数下，形成的两两相邻区间是 n - 1 个，比如 [2,4,6,8] 这里
        // 有 4 个数，但是只有 3 个区间，[2,4], [4,6], [6,8]
        // 因此，桶长度 = 区间总长度 / 区间总个数 = (max - min) / (nums.length - 1)
        int bucketSize = max((maxNum - minNum) / (n - 1), 1); // 桶的大小

        // 上面得到了桶的长度，我们就可以以此来确定桶的个数
        // 桶个数 = 区间长度 / 桶长度
        // 这里考虑到实现的方便，多加了一个桶，为什么？
        // 还是举上面的例子，[2,4,6,8], 桶的长度 = (8 - 2) / (4 - 1) = 2
        //                           桶的个数 = (8 - 2) / 2 = 3
        // 已知一个元素，需要定位到桶的时候，一般是 (当前元素 - 最小值) / 桶长度
        // 这里其实利用了整数除不尽向下取整的性质
        // 但是上面的例子，如果当前元素是 8 的话 (8 - 2) / 2 = 3，对应到 3 号桶
        //              如果当前元素是 2 的话 (2 - 2) / 2 = 0，对应到 0 号桶
        // 你会发现我们有 0,1,2,3 号桶，实际用到的桶是 4 个，而不是 3 个
        // 透过例子应该很好理解，但是如果要说根本原因，其实是开闭区间的问题
        // 这里其实 0,1,2 号桶对应的区间是 [2,4),[4,6),[6,8)
        // 那 8 怎么办？多加一个桶呗，3 号桶对应区间 [8,10)
        int count = (maxNum - minNum) / bucketSize + 1; // 桶的个数

        vector<int> bucketsMin(count, INT_MAX);
        vector<int> bucketsMax(count, INT_MIN);
        for (const auto& num : nums) {
            int index = (num - minNum) / bucketSize;
            bucketsMin[index] = min(bucketsMin[index], num);
            bucketsMax[index] = max(bucketsMax[index], num);
        }

        int result = 0;
        int previous = 0;
        for (int i = 1; i < count; ++i) {
            if (bucketsMin[i] == INT_MAX || bucketsMax[i] == INT_MIN) {
                continue;
            }
            // 从相邻的桶中找最大间距
            result = max(result, bucketsMin[i] - bucketsMax[previous]);
            previous = i;
        }

        return result;
    }
};
