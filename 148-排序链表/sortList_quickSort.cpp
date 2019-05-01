#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快排
class Solution {
public:
    ListNode* sortList(ListNode *head) {
        return quickSort(head);
    }

private:
    ListNode* quickSort(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *node = head;
        ListNode *indexNode = head->next;
        ListNode *leftHead = new ListNode(-1);
        ListNode *left = leftHead;
        ListNode *rightHead = new ListNode(-1);
        ListNode *right = rightHead;
        while (indexNode != NULL) {
            if (indexNode->val <= node->val) {
                left->next = indexNode;
                left = left->next;
            } else {
                right->next = indexNode;
                right = right->next;
            }
            indexNode = indexNode->next;
        }
        left->next = NULL;
        right->next = NULL;

        ListNode *newHead = NULL; // 新链表头结点
        ListNode *current = NULL;
        if (leftHead->next != NULL) { // 左链表不为空
            newHead = quickSort(leftHead->next);
            current = newHead;
            while (current != NULL && current->next != NULL) {
                current = current->next;
            }
            current->next = node;
            current = current->next;
        } else {
            newHead = node;
            current = newHead;
        }

        if (rightHead->next != NULL) { // 右链表不为空
            current->next = quickSort(rightHead->next);
        } else {
            current->next = NULL;
        }

        return newHead;
    }
};