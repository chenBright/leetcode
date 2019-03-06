#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            digits.push_back(1);
            return digits;
        }

        int binary = 1; // 进位，0或1
        vector<int>::reverse_iterator it = digits.rbegin();
        while (it != digits.rend()) {
            int temp = *it + binary;
            if (temp == 10) {
                *it = 0;
                binary = 1;
            } else {
                *it = temp;
                binary = 0;
            }
            ++it;
        }

        if (binary == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};