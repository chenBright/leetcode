#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) {
            return result;
        }

        generate("", 0, 0, n, result);

        return result;
    }

private:
    void generate(string str, int left, int right, int n, vector<string> &result) {
        if (left + right == 2 * n) {
            result.push_back(str);
            return;
        }

        // 只要左括号没够 n 个，都可以添加到左括号
        if (left < n) {
            generate(str + "(", left + 1, right, n, result);
        }

        // 只有左括号数大于右括号数，才可以添加到右括号；
        // 不然，会生成不合法字符，即右括号与左括号不匹配
        if (left > right) {
            generate(str + ")", left, right + 1, n, result);
        }

    }
};
