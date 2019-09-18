class Solution {
public:
    bool isPerfectSquare(int num) {
        // 使用 i * i <= num 判断，会有溢出风险
        for (int i = 1; i <= num / i; ++i) {
            if (i * i == num) {
                return true;
            }
        }
        return false;
    }
};