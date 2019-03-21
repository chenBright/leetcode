#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        int aLength = getListLength(headA);
        int bLength = getListLength(headB);

        // 长链表的结点指针先偏移offset单位，这样两个链表右对齐后，同步遍历比较两个链表的结点
        if (aLength > bLength) {
            for (int i = 0; i < aLength - bLength; ++i) {
                headA = headA->next;
            }
        } else {
            for (int j = 0; j < bLength - aLength; ++j) {
                headB = headB->next;
            }
        }

        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }

private:
    // 获取链表长度
    int getListLength(ListNode *head) {
        int length = 0;
        while (head != NULL) {
            head = head->next;
            ++length;
        }

        return length;
    }
};