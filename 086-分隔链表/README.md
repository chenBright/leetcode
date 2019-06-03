# 086-分隔链表

## 题目

leetcode：[086-分隔链表](https://leetcode-cn.com/problems/partition-list/)


## 思路

使用两个链表，一个链表保存小于x的结点，一个链表保存大于等于x的结点，最后将两个链表连接在一起。

```c++
class Solution {
public:
    ListNode* partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy1 = new ListNode(-1); // 小链表
        ListNode *dummy2 = new ListNode(-1); // 大链表
        ListNode *tail1 = dummy1; // 小链表尾结点
        ListNode *tail2 = dummy2; // 大链表尾结点
        ListNode *curNode = NULL;
        ListNode *oldNode = head;
        while (oldNode != NULL) {
            curNode = oldNode;
            oldNode = oldNode->next;
            curNode->next = NULL;

            if (curNode->val < x) {
                tail1->next = curNode;
                tail1 = curNode;
            } else {
                tail2->next = curNode;
                tail2 = curNode;
            }
        }
        // 大小链表连接在一起
        tail1->next = dummy2->next;

        return dummy1->next;
    }
};
```

