# 148-排序链表

## 题目

leetcode：[148-排序链表](https://leetcode-cn.com/problems/sort-list/)

## 归并排序

对链表的归并排序，关键在于找到链表的中点。该方法使用快慢指针找链表中点，慢指针走一步，快指针走两步。

```c++
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
```

## 快速排序

使用快速排序对链表排序，关键在于最后将链表链接好。快速排序的基本思想为：使用一个基准结点，将链表分为左链表和右链表。对左右链表递归执行这一步。最后要将左右链表和基准结点链接好。


```c++
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        pair<ListNode*, ListNode*> nodes = paritition(head);

        ListNode* left = sortList(nodes.first);
        ListNode* right = sortList(nodes.second);

        head->next = right;

        ListNode* leftTail = tail(left);
        if (leftTail != NULL) {
            leftTail->next = head;
            return left;
        } else {
            return head;
        }
    }

private:
    pair<ListNode*, ListNode*> paritition(ListNode* head) {
        if (head == NULL) {
            // 不能使用 NULL
            // 因为在 C++ 中 NULL 的定义为 #define NULL 0，
            // C++ 不允许将整型转换为指针类型。
            return make_pair(nullptr, nullptr);
        }

        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);
        ListNode* node = head->next;
        while (node != NULL) {
            ListNode* tmp = node;
            node = node->next;
            if (tmp->val <= head->val) {
                tmp->next = left->next;
                left->next = tmp;
            } else {
                tmp->next = right->next;
                right->next = tmp;
            }
        }

        return make_pair(left->next, right->next);
    }

    ListNode* tail(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        while (head->next != NULL) {
            head = head->next;
        }

        return head;
    }
};
```

