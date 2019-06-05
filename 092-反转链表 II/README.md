# 092-反转链表 II

## 题目

leetcode：[092-反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

## 一次遍历

1. 找到第一个反转结点，以及记录其前一个结点`beforreStartNode`。
2. 遍历反转结点，将其插入到结点`beforreStartNode`和第一个反转结点之间。
3. 遍历完反转结点后，此时遍历指针指向最后一个反转结点后一个结点，直接使第一个反转结点的`next`指向它。

```c++
class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        int index = 1;
        ListNode *node = head;
        ListNode *beforreStartNode = dummy; // 位置 m - 1上的结点
        // 找到第一个反转的结点，即位置 m 上的结点
        while (index < m && node != NULL) {
            beforreStartNode = node;
            node = node->next;
            ++index;
        }

        ListNode *end = node;
        node = node->next;
        ++index;
        // 反转
        while (index <= n && node != NULL) {
            ListNode *tmpNode = node;
            node = node->next;

            tmpNode->next = beforreStartNode->next;
            beforreStartNode->next = tmpNode;
            ++index;
        }
        // 此时 node 指向位置 n + 1，即最后一个反转结点后面一个结点
        end->next = node;

        return dummy->next;
    }
};
```