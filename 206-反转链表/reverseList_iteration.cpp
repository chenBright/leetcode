#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *newHead = NULL;
        ListNode *node = NULL;
        while (head != NULL) {
            node = head;
            head = head->next;
            node->next = newHead;
            newHead= node; 
        }

        return newHead;
    }
};
