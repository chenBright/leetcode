#include <vector>
#include <set>
#include <functional>
using namespace std;

// 构造含有k个元素红黑树，使用剩下的元素更新红黑树
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        multiset<int, less<int> > maxSet;
        multiset<int, less<int> >::iterator maxIt;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (maxSet.size() < k) { // 构造含有k个元素红黑树（小堆）
                maxSet.insert(*it);
            } else {
                maxIt = maxSet.begin();
                // 如果元素比堆顶元素大，则删除堆顶元素，然后插入该元素
                if (*it > *maxIt) {
                    maxSet.erase(maxIt);
                    maxSet.insert(*it);
                }
            }
        }

        return *maxSet.begin();
    }
};