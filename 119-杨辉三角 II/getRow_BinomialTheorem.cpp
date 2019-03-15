#include <vector>
using namespace std;

/**
 * 二项式定理
 * 参考
 * https://www.cnblogs.com/henry-1202/p/about_combinatorial_number.html
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1, 1);
        int64_t temp = 1;
        ++rowIndex; // 从0开始
        for (int i = 1; i < rowIndex; ++i) {
            temp = temp * (rowIndex - i) / i;
            res.push_back(int(temp));
        }

        return res;
    }
};