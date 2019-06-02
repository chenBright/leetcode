#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode *preNode = dummy;
        ListNode *curNode = head;
        bool hasEqual = false; // 是否存在重复的元素
        while (curNode != NULL && curNode->next != NULL) {
            if (curNode->val == curNode->next->val) {
                curNode = curNode->next;
                hasEqual = true;
            } else {
                if (hasEqual) {
                    preNode->next = curNode->next;
                    curNode->next = NULL;
                    curNode = preNode->next;
                } else {
                    preNode = curNode;
                    curNode = curNode->next;
                }
                hasEqual = false;
            }
        }

        // 如果最后的元素为重复的元素，如 [1,2,3,3]，这些元素未在循环中处理
        if (hasEqual) {
            preNode->next = NULL;
        }

        return dummy->next;
    }
};