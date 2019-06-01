#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1); // 设置一个前置结点，这样可以不用专门处理头结点无“前结点”的情况
        dummy->next = head;
        ListNode *preNode = dummy;
        ListNode *curNode = head;
        while (curNode != NULL && curNode->next != NULL) {
            // 交换
            preNode->next = curNode->next;
            curNode->next = curNode->next->next;
            preNode->next->next = curNode;

            preNode = curNode;
            curNode = curNode->next;
        }

        return dummy->next;
    }
};