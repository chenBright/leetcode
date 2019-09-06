class Solution {
public:
    bool isPowerOfThree(int n) {
        int m = 1;
        while (m < n) {
            m *= 3;
        }

        return m == n;
    }
};