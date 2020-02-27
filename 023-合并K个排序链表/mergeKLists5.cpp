#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        int length = lists.size();
        // 非递归归并排序的归并思路
        for (int interval = 1; interval < length; interval *= 2) { // 间隔
            for (int i = 0; i < length - interval; i += 2 * interval) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
        }

        return lists[0];
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* lastNode = dummy;
        while (l1 != NULL && l2 != NULL) {
            ListNode* node = NULL;
            if (l1->val < l2->val) {
                node = l1;
                l1 = l1->next;
            } else {
                node = l2;
                l2 = l2->next;
            }
            node->next = dummy->next;
            lastNode->next = node;
            lastNode = lastNode->next;
        }

        if (l1 != NULL) {
            lastNode->next = l1;
        }
        if (l2 != NULL) {
            lastNode->next = l2;
        }

        return dummy->next;
    }
};
