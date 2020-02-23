#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowP = head;
        ListNode* fastP = head;
        while (fastP != NULL && fastP->next != NULL) {
            slowP = slowP->next;
            fastP = fastP->next->next;

            if (slowP == fastP) {
                break;
            }
        }

        // 无环
        if (fastP == NULL || fastP->next == NULL) {
            return NULL;
        }

        slowP = head;
        while (slowP != fastP) {
            slowP = slowP->next;
            fastP = fastP->next;
        }

        return slowP;
    }
};
