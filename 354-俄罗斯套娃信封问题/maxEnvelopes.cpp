#include <vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp;
        for (const auto& envelope : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }

        return dp.size();
    }
private:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
};
