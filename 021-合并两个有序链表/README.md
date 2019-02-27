# 021-合并两个有序链表

## 题目

leetcode：[021-合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)


## 思路

用两个指针同时遍历两个链表，取出最小的结点，插入到新链表中，而被取出结点的链表的指针指向下一个结点

## 循环实现

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        // 先确定头结点
        ListNode *root = NULL;
        if (l2->val < l1->val) {
            root = l2;
            l2 = l2->next;
        } else {
            root = l1;
            l1 = l1->next;
        }

        ListNode *node = root;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }

        if (l1 == NULL) {
            node->next = l2;
        } else if (l2 == NULL) {
            node->next = l1;
        }

        return root;
    }
};
```

## 递归实现

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *node = NULL;
        if (l2->val < l1->val) {
            node = l2;
            l2 = l2->next;
        } else {
            node = l1;
            l1 = l1->next;
        }

        node->next = mergeTwoLists(l1, l2);

        return node;
    }
};
```

