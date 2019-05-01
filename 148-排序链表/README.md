# 148-排序链表

## 题目

leetcode：[148-排序链表](https://leetcode-cn.com/problems/sort-list/)

## 归并排序

对链表的归并排序，关键在于找到链表的中点。该方法使用快慢指针找链表中点，慢指针走一步，快指针走两步。

```c++
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
```

## 快速排序

使用快速排序对链表排序，关键在于最后将链表链接好。快速排序的基本思想为：使用一个基准结点，将链表分为左链表和右链表。对左右链表递归执行这一步。最后要将左右链表和基准结点链接好。

1. 如果做链表不为空，则新链表的头结点为左链表的头结点；否则，新链表的头结点为基准结点。
2. 链接基准结点和右结点。

```c++

```

