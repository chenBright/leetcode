#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) {
            result.push_back("");
        } else {
            for (int i = 0; i < n; ++i) {
                vector<string> lefts;
                if (results.count(i)) {
                    lefts = results[i];
                } else {
                    lefts = generateParenthesis(i);
                    results[i] = lefts;
                }

                for (const auto &left : lefts) {
                    vector<string> rights;
                    int tmp = n - 1 - i;
                    if (results.count(tmp)) {
                        rights = results[tmp];
                    } else {
                        rights = generateParenthesis(tmp);
                        results[tmp] = rights;
                    }
                    
                    for (const auto &right : rights) {
                        result.push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return result;
    }

private:
    unordered_map<int, vector<string> > results;
};
