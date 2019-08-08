#include <vector>
#include <algorithm>
using namespace std;

// 计数排序
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> papers(n + 1, 0); // paper[i]：引用数为 i 的文章数
        for (const auto &c : citations) {
            ++papers[min(n, c)];
        }

        int citation = n; // 引用数
        // count：文章数
        for (int count = papers[citation]; citation > count; count += papers[citation]) {
            --citation;
        }

        return citation;
    }
};
