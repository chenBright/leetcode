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
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *pSlow = head->next; // 慢指针
        ListNode *pFast = pSlow->next; // 快指针

        bool hasCycle = false;
        while (pFast != NULL && pFast->next != NULL) {
            if (pSlow == pFast) {
                hasCycle = true;
                break;
            }

            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        if (!hasCycle) {
            return NULL;
        }

        pFast = head; // 复用快指针
        while (pFast != pSlow) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }

        return pSlow;
    }

};
