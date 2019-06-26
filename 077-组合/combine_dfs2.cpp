#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if (n == 0 || k == 0) {
            return result;
        }

        combineRecursion(1, n, k);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;

    void combineRecursion(int start, int end, int k) {
        if (tmpResult.size() >= k) {
            result.push_back(tmpResult);
            return;
        }

        if (end - start + 1 < k - tmpResult.size()) {
            return;
        }

        for (int i = start; i <= end; ++i) {
            tmpResult.push_back(i);
            combineRecursion(i + 1, end, k);
            tmpResult.pop_back();
        }
    }
};