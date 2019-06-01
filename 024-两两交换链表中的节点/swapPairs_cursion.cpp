#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *newHead = head->next;
        ListNode *node = head->next->next;
        // 交换结点
        newHead->next = head;
        head->next = swapPairs(node); // 防止断链

        return newHead;
    }
};