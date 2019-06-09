#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode *head, int val) {
        if (head == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curNode = dummy;
        ListNode *nextNode = curNode->next;
        while (curNode != NULL && nextNode != NULL) {
            if (nextNode->val == val) {
                while (nextNode != NULL && nextNode->val == val) {
                    nextNode = nextNode->next;
                }
                curNode->next = nextNode;
            } else {
                curNode = curNode->next;
                nextNode = nextNode->next;
            }
        }

        return dummy->next;
    }
};