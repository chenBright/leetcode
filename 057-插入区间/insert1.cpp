#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > result;
        
        int current = 0;
        int length = intervals.size();
        // 将前面的区间加入结果中
        while (current < length && intervals[current][1] < newInterval[0]) {
            result.push_back(intervals[current]);
            ++current;
        }

        // 更新重叠的区间，最后加入结果中
        while (current < length && intervals[current][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[current][0], newInterval[0]);
            newInterval[1] = max(intervals[current][1], newInterval[1]);
            ++current;
        }
        result.push_back(newInterval);

        // 将后面的区间加入结果中
        while (current < length) {
            result.push_back(intervals[current]);
            ++current;
        }

        return result;
    }
};
