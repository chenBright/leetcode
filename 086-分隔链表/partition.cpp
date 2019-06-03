#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy1 = new ListNode(-1); // 小链表
        ListNode *dummy2 = new ListNode(-1); // 大链表
        ListNode *tail1 = dummy1; // 小链表尾结点
        ListNode *tail2 = dummy2; // 大链表尾结点
        ListNode *curNode = NULL;
        ListNode *oldNode = head;
        while (oldNode != NULL) {
            curNode = oldNode;
            oldNode = oldNode->next;
            curNode->next = NULL;

            if (curNode->val < x) {
                tail1->next = curNode;
                tail1 = curNode;
            } else {
                tail2->next = curNode;
                tail2 = curNode;
            }
        }
        // 大小链表连接在一起
        tail1->next = dummy2->next;

        return dummy1->next;
    }
};
