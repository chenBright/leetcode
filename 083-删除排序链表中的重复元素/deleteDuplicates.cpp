#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }

        ListNode *newEndPtr = head;
        ListNode *nodePtr = head->next;

        while (nodePtr != NULL) {
            if (nodePtr->val != newEndPtr->val) {
                newEndPtr->next = nodePtr;
                newEndPtr = newEndPtr->next;
            }
            nodePtr = nodePtr->next;
        }
        newEndPtr->next = NULL; // 最后一个元素的next指向NULL

        return head;
    }
};