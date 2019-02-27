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

        // 先确定头结点
        ListNode *root = NULL;
        if (l2->val < l1->val) {
            root = l2;
            l2 = l2->next;
        } else {
            root = l1;
            l1 = l1->next;
        }

        ListNode *node = root;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }

        if (l1 == NULL) {
            node->next = l2;
        } else if (l2 == NULL) {
            node->next = l1;
        }

        return root;
    }
};
