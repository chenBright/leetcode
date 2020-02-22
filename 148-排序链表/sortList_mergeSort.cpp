#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* midNode = mid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(midNode);

        return merge(left, right);
    }
private:
    ListNode* mid(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* slowP = head;
        ListNode* fastP = head;
        ListNode* preNode;
        while (fastP != NULL && fastP->next != NULL) {
            preNode = slowP;
            slowP = slowP->next;
            fastP = fastP->next->next;
        }
        // 将链表分成两个链表
        preNode->next = NULL;

        return slowP;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        }

        ListNode* head;
        if (left->val <= right->val) {
            head = left;
            left = left->next;
        } else {
            head = right;
            right = right->next;
        }

        ListNode* node = head;
        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }

        if (left == NULL) {
            node->next = right;
        } else if (right == NULL) {
            node->next = left;
        }

        return head;
    }
};
