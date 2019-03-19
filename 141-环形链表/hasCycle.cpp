#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next) {
            return false;
        }

        ListNode *pSlow = head->next; // 慢指针
        ListNode *pFast = pSlow->next; // 快指针

        while (pSlow != NULL && pFast != NULL) {
            if (pSlow == pFast) {
                return true;
            }

            pSlow = nextNode(pSlow, 1);
            pFast = nextNode(pFast, 2);
        }

        return false;
    }

private:
    // 下一结点
    ListNode* nextNode(ListNode* node, int step) {
        for (int i = 0; i < step && node != NULL; ++i) {
            node = node->next;
        }

        return node;
    }
};