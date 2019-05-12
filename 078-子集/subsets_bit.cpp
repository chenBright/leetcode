#include <vector>
#include <cmath>
using namespace std;

// 位运算
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res;
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        res.push_back(vector<int>()); // 空集合
        
        // 每个数字代表一个位，有两种情况（取或不取），总共 2 ^ length 中情况
        int subLength = pow(2, length); 
        int hash = 1; // 当前取数情况
        while (hash < subLength) {
            vector<int> temp;
            for (int i = 0; i < length; ++i) {
                int a = 1 << i; // 表示第 i 位，每次想左移1位
                if (a & hash) {
                    temp.push_back(nums[i]);
                }
            }
            res.push_back(temp);
            ++hash;
        }

        return res;
    }
};