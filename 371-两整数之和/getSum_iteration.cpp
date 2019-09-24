class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // leetcode 编译器不允许对负数进行左移，即最高位符号位必须要为0，才能左移
            int carry = static_cast<unsigned long>(a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};