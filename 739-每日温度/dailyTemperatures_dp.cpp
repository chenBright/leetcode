#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) {
            return vector<int>();
        }

        int length = T.size();
        vector<int> result(length, 0);
        
        for (int i = length - 2; i >= 0; --i) {
            for (int j = i + 1; j < length; j += result[j]) {
                if (T[i] < T[j]) {
                    result[i] = j - i;
                    break;
                } else if (result[j] == 0) {
                    result[i] = 0;
                    break;
                }
            }
        }

        return result;
    }
};
