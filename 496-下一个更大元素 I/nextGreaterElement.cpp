#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() | nums2.empty()) {
            return result;
        }

        stack<int> s; // 单调栈
        unordered_map<int, int> m;
        for (const auto& num : nums2) {
            while (!s.empty() && num > s.top()) {
                m[s.top()] = num; // 栈顶元素下一个的元素为 num
                s.pop();
            } // 保持栈内元素从栈底到栈顶单调不增
            s.push(num);
        }

        // 栈中剩下的元素不存在下一个更大的元素
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }

        for (const auto& num : nums1) {
            result.push_back(m[num]);
        }

        return result;
    }
};
