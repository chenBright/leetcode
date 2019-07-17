#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.empty() || t < 0) {
            return false;
        }

        unordered_map<long, long> m;
        long bucketSize = static_cast<long>(t) + 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.size() > k) {
                m.erase(getBucketId(nums[i - k - 1], bucketSize));
            }

            long id = getBucketId(nums[i], bucketSize);
            // 如果桶内已经有元素，则这两个数字肯定符合条件
            if (m.find(id) != m.end()) {
                return true;
            }
            // 检查与相邻桶内元素是否满足条件
            if (m.find(id + 1) != m.end() && abs(nums[i] - m[id + 1]) <= t) {
                return true;
            }
            if (m.find(id - 1) != m.end() && abs(nums[i] - m[id - 1]) <= t) {
                return true;
            }

            m[id] = nums[i];
        }

        return false;
    }

private:

    long getBucketId(long value, long bucketSize){
        return value < 0 ? (value + 1) / bucketSize - 1 : value / bucketSize;
    } 
};