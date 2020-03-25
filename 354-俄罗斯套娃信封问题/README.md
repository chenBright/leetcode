# 354-俄罗斯套娃信封问题

## 题目

leetcode：[354-俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)

## 排序 + 最长公共子序列（LIS）

参考[LeetCode官方题解](https://leetcode-cn.com/problems/russian-doll-envelopes/solution/e-luo-si-tao-wa-xin-feng-wen-ti-by-leetcode/)。

```c++
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
```

