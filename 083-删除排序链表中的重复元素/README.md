# 083-删除排序链表中的重复元素

## 题目

leetcode：[083-删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)


## 思路

该题目与[026-删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)思路一样，不同的是对数组和链表的处理有一点不一样而已。

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }

        ListNode *newEndPtr = head;
        ListNode *nodePtr = head->next;

        while (nodePtr != NULL) {
            if (nodePtr->val != newEndPtr->val) {
                newEndPtr->next = nodePtr;
                newEndPtr = newEndPtr->next;
            }
            nodePtr = nodePtr->next;
        }
        newEndPtr->next = NULL; // 最后一个元素的next指向NULL

        return head;
    }
};
```

