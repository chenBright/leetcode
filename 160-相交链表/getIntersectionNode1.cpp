#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        if (lengthA > lengthB) {
            headA = nextNode(headA, lengthA - lengthB);
        } else if (lengthA < lengthB) {
            headB = nextNode(headB, lengthB - lengthA);
        }

        // 长链表的结点指针先偏移 offset 单位，这样两个链表右对齐后，同步遍历比较两个链表的结点。
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
    int getLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            ++length;
            head = head->next;
        }

        return length;
    }

    ListNode* nextNode(ListNode* node, int step) {
        for (int i = 0; i < step && node != NULL; ++i) {
            node = node->next;
        }

        return node;
    }
};
