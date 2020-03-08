#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty()) {
            return result;
        }

        sort(intervals.begin(), intervals.end(), Compare());

        int left = intervals[0][0];
        int right = intervals[0][1];
        int length = intervals.size();
        for (int i = 1; i < length; ++i) {
            if (right >= intervals[i][0]) {
                if (right < intervals[i][1]) {
                    right = intervals[i][1];
                }
            } else {
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.push_back({left, right});


        return result;
    }
private:
    struct Compare {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        }
    };
};
