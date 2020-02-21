#include <vector>
#include <set>
#include <functional>
using namespace std;

// 构造含有 k 个元素红黑树，使用剩下的元素更新红黑树。
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int length = nums.size();
        if (nums.empty() || k == 0 || k > length) {
            return -1;
        }

        // 构造含有 k 个元素红黑树（小堆）
        multiset<int, less<int> > maxSet(nums.begin(), nums.begin() + k);

        for (int i = k; i < length; ++i) {
            auto it = maxSet.begin();
            // 如果元素比堆顶元素大，则删除堆顶元素，然后插入该元素。
            if (nums[i] > *it) {
                maxSet.erase(it);
                maxSet.insert(nums[i]);
            }
        }

        return *maxSet.begin();
    }
};
