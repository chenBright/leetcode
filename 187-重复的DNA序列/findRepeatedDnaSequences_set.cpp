#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<string> sSet;
        unordered_set<string> tmpSet;
        for (int i = 0; i + 9 < len; ++i) {
            string tmp(s.substr(i, 10));
            if (sSet.count(tmp)) {
                tmpSet.insert(tmp);
            } else {
                sSet.insert(tmp);
            }
        }

        return vector<string>(tmpSet.begin(), tmpSet.end());
    }
};
