#include <vector>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 排序
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) {
            return NULL;
        }

        vector<int> v;
        for (const auto &list : lists) {
            ListNode *node = list;
            while (node != NULL) {
                v.push_back(node->val);
                node = node->next;
            }
        }

        sort(v.begin(), v.end());

        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        for (int i = 0; i < v.size(); ++i) {
            current->next = new ListNode(v[i]);
            current = current->next;
        }

        return dummy->next;
    }
};
