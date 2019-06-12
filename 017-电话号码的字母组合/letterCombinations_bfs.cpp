#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        unordered_map<char, string> table{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},{'8', "tuv"}, {'9', "wxyz"}
        };

        result.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> tmp;
            string chars = table[digits[i]];
            for (const auto &lastStr : result) {
                for (const auto &c : chars) {
                    tmp.push_back(lastStr + c);
                }
            }
            result = tmp;
        }

        return result;
    }
};