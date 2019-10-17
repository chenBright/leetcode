#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();

        if (length1 > length2) {
            return false;
        }
        
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);

        for (int i = 0; i < length1; ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }

        if (m1 == m2) {
            return true;
        }

        for (int j = length1; j < length2; ++j) {
            ++m2[s2[j] - 'a'];
            --m1[s2[j - length1] - 'a'];

            if (m1 == m2) {
                return true;
            }
        }

        return false;
    }
};
