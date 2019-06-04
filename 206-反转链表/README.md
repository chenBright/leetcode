# 206-反转链表

## 题目

leetcode：[206-反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

## 迭代

```c++
class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *newHead = NULL;
        ListNode *node = NULL;
        while (head != NULL) {
            node = head;
            head = head->next;
            node->next = newHead;
            newHead= node; 
        }

        return newHead;
    }
};
```

## 递归

```c++
class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *node = reverseList(head->next); // 先反转后面的结点
        // 反转
        head->next->next = head; // 此时 head 结点还没断开，next 指向的是已经反转的链表的尾结点
        head->next = NULL;

        return node;
    }
};
```