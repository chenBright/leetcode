#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) {
            return head;
        }

        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *dummy = new ListNode(-1); // 辅助头结点
        dummy->next = head;
        ListNode *current = dummy; // 被删除结点的前一个结点
        ListNode *end = dummy;

        int i = 0;
        while (end != NULL && current != NULL) {
            if (i > n) {
                current = current->next;
            }
            end = end->next;
            ++i;
        }
        current->next = current->next->next;

        return dummy->next;
    }
};