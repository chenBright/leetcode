#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode *head) {
        return head == NULL ? head : mergeSort(head);
    }

private:
    ListNode* mergeSort(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *p = head; // 慢指针
        ListNode *q = head; // 快指针
        ListNode *pre = NULL;
        // 快慢指针找中点
        while (q != NULL && q->next != NULL) {
            pre = p;
            p = p->next;
            q = q->next->next;
        }
        pre->next = NULL;
        ListNode *left = mergeSort(head);
        ListNode *right = mergeSort(p);
        return merge(left, right);
    }

    // 归并
    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *current = dummyHead;
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                current->next = left;
                current = current->next;
                left = left->next;
            } else {
                current->next = right;
                current = current->next;
                right = right->next;
            }
        }
        current->next = left == NULL ? right : left;

        return dummyHead->next;
    }
};