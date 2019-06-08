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

        ListNode *node = reverseList(head->next); // 先反转后面的结点
        // 反转
        head->next->next = head; // 此时 head 结点还没断开，next 指向的是已经反转的链表的尾结点
        head->next = NULL;

        return node;
    }
};
