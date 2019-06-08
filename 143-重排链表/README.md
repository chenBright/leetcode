# 143-重排链表

## 题目

leetcode：[143-重排链表](https://leetcode-cn.com/problems/reorder-list/)

## 快慢指针 + 反转链表

先使用快慢指针找出中间结点，然后反转后半部分链表，最后重排链表。

注：不不要分别处理链表长度奇偶数的问题，详细见注释。

```c++
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        // 使用双端队列保存结点
        deque<ListNode*> nodeDeque;
        while (head != NULL) {
            nodeDeque.push_back(head);
            head = head->next;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *curNode = dummy;
        while (!nodeDeque.empty()) {
            curNode->next = nodeDeque.front();
            nodeDeque.pop_front();
            curNode = curNode->next;
            if (!nodeDeque.empty()) {
                curNode->next = nodeDeque.back();
                nodeDeque.pop_back();
                curNode = curNode->next;
            }
        }
        // 处理链表尾，不然会导致链表“成环”，
        // LeetCode 验证结果的时候出现死循环，最后超出时间限制
        curNode->next = NULL;
    }
};
```

## 双端队列

使用双端队列保存链表的结点，然后每次分别从队列头尾弹出一个结点连接成新链表，直到双端队列为空。

注：诸侯一个结点的`next`指针要指向`NULL`，不然重排后的链表会出现“环”，LeetCode 验证结果的时候出现死循环，最后导致超出时间限制。

```c++
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        // 使用双端队列保存结点
        deque<ListNode*> nodeDeque;
        while (head != NULL) {
            nodeDeque.push_back(head);
            head = head->next;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *curNode = dummy;
        while (!nodeDeque.empty()) {
            curNode->next = nodeDeque.front();
            nodeDeque.pop_front();
            curNode = curNode->next;
            if (!nodeDeque.empty()) {
                curNode->next = nodeDeque.back();
                nodeDeque.pop_back();
                curNode = curNode->next;
            }
        }
        // 处理链表尾，不然重排后的链表会出现“环”，
        // LeetCode 验证结果的时候出现死循环，最后导致超出时间限制
        curNode->next = NULL;
    }
};
```