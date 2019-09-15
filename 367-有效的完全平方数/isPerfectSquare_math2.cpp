// 牛顿迭代法
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }

        long r = num;
        while (r * r > num) {
            r = (r + num / r) / 2;
        }

        return r * r == num;
    }
};