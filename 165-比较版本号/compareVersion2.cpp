#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream is1(version1 + ".");
        istringstream is2(version2 + ".");
        int num1 = 0;
        int num2 = 0;
        char dot = '.';
        while (is1.good() || is2.good()) {
            if (is1.good()) {
                is1 >> num1 >> dot;
            }
            if (is2.good()) {
                is2 >> num2 >> dot;
            }

            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
            num1 = num2 = 0;
        }

        return 0;
    }
};
