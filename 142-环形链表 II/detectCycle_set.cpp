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
        if (!hasCycle(head)) {
            return NULL;
        }

        unordered_set<ListNode*> nodeSet;
        ListNode *node = head;
        while (nodeSet.find(node) == nodeSet.end()) {
            nodeSet.insert(node);
            node = node->next;
        }

        return node;
    }

private:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *pSlow = head->next; // 慢指针
        ListNode *pFast = pSlow->next; // 快指针

        while (pFast != NULL && pFast->next != NULL) {
            if (pSlow == pFast) {
                return true;
            }

            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        return false;
    }
};
