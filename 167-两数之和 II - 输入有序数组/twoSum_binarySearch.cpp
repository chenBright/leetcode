#include <vector>
using namespace std;

// 二分查找
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if (numbers.empty()) {
            return res;
        }

        for (int i = 0; i < numbers.size(); ++i) {
            int anotherNum = target - numbers[i];
            int index = binarySearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            // 查找成功
            if (index != -1) {
                res.push_back(i + 1);
                res.push_back(index + 1);
                break;
            }  
        }

        return res;
    }

private:
    // 二分查找，如果查找成功，则返回索引值；否则，返回 -1
    int binarySearch(vector<int> &numbers, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (numbers[mid] == target) {
                return mid;
            } else if (numbers[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};