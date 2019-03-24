#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        map<int, int> numMap;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (numMap.count(*it)) {
                ++numMap[*it];
            } else {
                numMap[*it] = 1;
            }
        }

        for (map<int, int>::iterator it = numMap.begin(); it != numMap.end(); ++it) {
            if (it->second > nums.size() / 2) {
                return it->first;
            }
        }

        return 0;
    }
};