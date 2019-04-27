#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        int res = 0;
        int length = tokens.size();
        if (length == 0) {
            return res;
        }

        for (const auto &token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                nums.push(stoi(token));
            } else {
                int nowRes;
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if (token == "+") {
                    nowRes = num1 + num2;
                } else if (token == "-") {
                    nowRes = num1 - num2;
                } else if (token == "*") {
                    nowRes = num1 * num2;
                } else {
                    nowRes = num1 / num2;
                }
                nums.push(nowRes);
            }
        }
        return nums.top();
    }
};