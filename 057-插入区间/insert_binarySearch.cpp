#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        // 找到第一个 !comp == true 的元素，即找到第一个 intervals[i][0] <= newInterval[0] <= intervals[i][1]
        auto index = lower_bound(intervals.begin(), intervals.end(), newInterval, comp) - intervals.begin();
        
        int i = index;
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }

        intervals.insert(intervals.cbegin() + i, newInterval);
        intervals.erase(intervals.cbegin() + index, intervals.cbegin() + i);

        return intervals;
    }

private:
    static bool comp(const vector<int>& a, const vector<int>& b){
		return a[1] < b[0];
	}
};
