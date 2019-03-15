#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current(1, 1);
        if (rowIndex == 0) {
            return current;
        }

        vector<int> pre(current);
        vector<int>::iterator it;
        for (int i = 0; i < rowIndex; ++i) {
            for (it = pre.begin(); it != pre.end() && it + 1 != pre.end(); ++it) {
                int64_t temp = *it + *(it + 1); // 使用int64_t，避免整型溢出
                current.insert(current.end(), int(temp));
            }
            current.push_back(1); // 插入最后一个元素“1”
            pre = current;
            current.erase(current.begin() + 1, current.end()); // 只留下前面的元素“1”，其他元素都删除
        }

        return pre;
    }
};