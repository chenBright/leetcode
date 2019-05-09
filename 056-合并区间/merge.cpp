#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        vector<vector<int> > res;
        if (intervals.empty()) {
            return res;
        }

        sort(intervals.begin(), intervals.end(), compare);

        int i = 0;
        int left = intervals[i][0];
        int right = intervals[i][1];
        vector<int> temp(2, -1);
        while (++i < intervals.size()) {
            if (right < intervals[i][0]) {
                temp[0] = left;
                temp[1] = right;
                res.push_back(temp);
                left = intervals[i][0];
                right = intervals[i][1];

            } else if (right < intervals[i][1]) {
                right = intervals[i][1];
            }
        }
        temp[0] = left;
        temp[1] = right;
        res.push_back(temp);

        return res;
    }

    static bool compare(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
};