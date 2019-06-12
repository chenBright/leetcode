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

        combinate(digits, 0, "", table, result);

        return result;

    }

private:
    void combinate(string &digits, int index, string str,
                   unordered_map<char, string> &table, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(str);
            return;
        }

        string chars = table[digits[index]];
        for (const auto &c : chars) {
            str += c;
            combinate(digits, index + 1, str, table, result);
            str.pop_back();
        }
    }
};