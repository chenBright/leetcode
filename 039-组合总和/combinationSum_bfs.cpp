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
        combinationSum(candidates, temp, low == length ? length - 1 : low, length - 1, target);

        return res;
    }

    static bool compare(int a, int b) {
        return a > b;
    }

private:
    vector<vector<int> > res;

    void combinationSum(vector<int> &candidates, vector<int> &resTemp, int low, int high, int target) {
        if (target == 0) {
            res.push_back(resTemp);
            return;
        } else if (target < 0 || low > high) {
            return;
        }

        // [low ... high]中每个元素都匹配一次
        for (int i = low; i <= high; ++i) {
            resTemp.push_back(candidates[i]);
            combinationSum(candidates, resTemp, i, high, target - candidates[i]);
            resTemp.pop_back();
        }
    }
};