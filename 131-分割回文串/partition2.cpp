#include <vector>
#include <string>
using namespace std;

// 不需要拷贝临时字符串，使用索引代替
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return result;
        }

        partitionRecursion(s, 0);

        return result;
    }

private:
    vector<vector<string> > result;
    vector<string> tmpResult;

    void partitionRecursion(string &s, int index) {
        int len = s.size();
        if (index >= len) {
            result.push_back(tmpResult);
        }

        for (int i = index; i < len; ++i) {
            if (isPalindromic(s, index, i)) {
                tmpResult.push_back(s.substr(index, i - index + 1));
                partitionRecursion(s, i + 1);
                tmpResult.pop_back();
            }
        }
    }
    // s[start …… end]是否为回文字符串
    bool isPalindromic(string &s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }

        return true;
    }
};