#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int length = candidates.size();
        if (length == 0) {
            return res;
        }

        sort(candidates.begin(), candidates.end(), compare); // 降序

        int low = 0;
        // 跳过值比 target 大的元素
        while (low < length) {
            if (candidates[low] <= target) {
                break;
            }
            ++low;
        }

        vector<int> temp;
        combinationSum(candidates, temp, 0, target);

        return res;
    }

    static bool compare(int a, int b) {
        return a > b;
    }

private:
    vector<vector<int> > res;

    void combinationSum(vector<int> &candidates, vector<int> resTemp, int index, int target) {
        if (target == 0) {
            res.push_back(resTemp);
            return;
        }

        if (target < 0 || index >= candidates.size()) {
            return;
        }

        int candidate = candidates[index];
        int num = target / candidate; // 最多能有几个 candidate
        // DFS（从target角度看）
        for (int i = 0; i <= num; ++i) {
            if (i != 0) {
                resTemp.push_back(candidate);
            }
            combinationSum(candidates, resTemp, index + 1, target - candidate * i);
        }
    }
};