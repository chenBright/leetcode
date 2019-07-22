#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }

        // 前后逐一对比
        int left = 0;
        int right = v.size() - 1;
        while (left < right) {
            if (v[left] != v[right]) {
                return false;
            }
            ++left;
            --right;
        }
        
        return true;
    }
};