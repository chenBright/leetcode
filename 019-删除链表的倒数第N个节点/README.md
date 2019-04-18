# 019-删除链表的倒数第N个节点

## 题目

leetcode：[019-删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)


## 双指针法

参考[LeetCode 删除链表的倒数第N个节点官方解答](ps://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/)。

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) {
            return head;
        }

        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *dummy = new ListNode(-1); // 辅助头结点
        dummy->next = head;
        ListNode *current = dummy; // 被删除结点的前一个结点
        ListNode *end = dummy;

        int i = 0;
        while (end != NULL && current != NULL) {
            if (i > n) {
                current = current->next;
            }
            end = end->next;
            ++i;
        }
        current->next = current->next->next;

        return dummy->next;
    }
};
```

