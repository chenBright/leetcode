#include <vector>
#include <algorithm>
using namespace std;

// 基于比较的排序
class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), greater<int>());

        // i + 1：文章数
        for (int i = 0; i < citations.size(); ++i) {
            if (i + 1 > citations[i]) {
                return i;
            }
        }

        return citations.size();
    }
};
