#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode *head, int k) {
        if (k <= 0 || head == NULL) {
            return head;
        }

        ListNode *newHead = new ListNode(-1); // 新链表头结点
        newHead->next = head;
        ListNode *first = head;
        ListNode *second = head;
        int length = 0;
        // 计算链表长度
        while (first != NULL) { 
            ++length;
            first = first->next;
        }

        k = k % length;
        // k 是 链表长度的整数倍，则不需要旋转
        if (length == k || k == 0) {
            return head;
        }

        first = head;
        for (int j = 0; j < k; ++j) { // 快指针
            first = first->next;
        }
        while (first != NULL && first->next != NULL) {
            first = first->next; // 最后，指向尾结点
            second = second->next; // 最后，指向倒数第 k+1 个结点
        }
        second->next = first->next; // 即 NULL
        first->next = head;

        return newHead;
    }
};