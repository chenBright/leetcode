#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > result;
        
        int index = 0; // 记录重叠区间的插入位置
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) {
                // 将前面的区间加入结果中
                result.push_back(intervals[i]);
                ++index;
            } else if (intervals[i][0] > newInterval[1]) {
                // 将前面的区间加入结果中
                result.push_back(intervals[i]);
            } else {
                // 更新重叠的区间，最后加入结果中
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }

        // 将重叠的区间插入结果中
        result.insert(result.cbegin() + index, newInterval);

        return result;
    }
};
