# 237-删除链表中的节点

## 题目

leetcode：[237-删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)

## 代码

```c++
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
    }
};
```