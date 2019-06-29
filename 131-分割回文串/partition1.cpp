#include <vector>
#include <string>
using namespace std;

// 需要拷贝临时字符串
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return result;
        }

        partitionRecursion(s);

        return result;
    }

private:
    vector<vector<string> > result;
    vector<string> tmpResult;

    void partitionRecursion(string s) {
        if (s.empty()) {
            result.push_back(tmpResult);
        }

        for (int i = 0; i < s.size(); ++i) {
            string tmp = s.substr(0, i + 1);
            if (isPalindromic(tmp)) {
                tmpResult.push_back(tmp);
                partitionRecursion(s.substr(i + 1));
                tmpResult.pop_back();
            }
        }
    }

    // s是否为回文字符串
    bool isPalindromic(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
};