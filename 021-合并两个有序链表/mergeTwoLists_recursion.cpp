#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *node = NULL;
        if (l2->val < l1->val) {
            node = l2;
            l2 = l2->next;
        } else {
            node = l1;
            l1 = l1->next;
        }

        node->next = mergeTwoLists(l1, l2);

        return node;
    }
};
