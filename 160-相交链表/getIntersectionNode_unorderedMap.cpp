#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while (headA != NULL) {
            s.insert(headA);
            headA = headA->next;
        }

        while (headB != NULL) {
            if (s.count(headB) != 0) {
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
};