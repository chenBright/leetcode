# 876-链表的中间结点

## 题目

leetcode：[876-链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)

## 快慢指针

```c++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```
