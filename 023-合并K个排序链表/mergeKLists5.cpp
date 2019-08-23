#include <vector>
#include <limits>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 计数排序
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) {
            return NULL;
        }

        unordered_map<int, int> m;
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        for (const auto &list : lists) {
            ListNode *node = list;
            while (node != NULL) {
                maxVal = max(node->val, maxVal);
                minVal = min(node->val, minVal);
                if (m.count(node->val) == 0) {
                    m[node->val] = 1;
                } else {
                    ++m[node->val];
                }
                node = node->next;
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        for (int i = minVal; i <= maxVal; ++i) {
            if (m.count(i) == 0) {
                continue;
            }

            while (m[i] > 0) {
                current->next = new ListNode(i);
                current = current->next;
                --m[i];
            }
        }

        return dummy->next;
    }
};
