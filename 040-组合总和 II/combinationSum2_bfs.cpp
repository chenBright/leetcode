#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
        } else if (target < 0) {
            return;
        }        

        // BFS（从target角度看）
        for (int i = low; i <= high && candidates[i] <= target; ++i) {
            /**
             * i == low 肯定取，表示至少取1个 。
             * 如果candidates[low] == candidates[low - 1]，
             * [low ... high] 包含了 [low - 1 ... high] 的结果，所以跳过，达到去重的效果
             */
            if (i != low && candidates[i] == candidates[i - 1]) {
                continue;
            }
            resTemp.push_back(candidates[i]);
            combinationSum(candidates, resTemp, i + 1, high, target - candidates[i]);
            resTemp.pop_back();
        }
    }
};