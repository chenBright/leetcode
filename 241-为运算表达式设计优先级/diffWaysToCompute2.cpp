#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (m.count(input)) {
            return m[input];
        }
        
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i)); // 符号左边的组合
                vector<int> right = diffWaysToCompute(input.substr(i + 1)); // 符号右边的组合

                // 使用符号，组合左右边结果，计算最后的结果
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') {
                            result.push_back(left[j] + right[k]);
                        } else if (input[i] == '-') {
                            result.push_back(left[j] - right[k]);
                        } else {
                            result.push_back(left[j] * right[k]);
                        }
                    }
                }
            }
        }

        // input 只是一个数字
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        m[input] = result;

        return result;
    }
private:
    unordered_map<string, vector<int> > m;
};