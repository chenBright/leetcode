# 328-奇偶链表

## 题目

leetcode：[328-奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)

## 实现

使用两个链表，一个保存奇数结点，一个保存偶数结点。最后将两个链表连接在一起即可。

```c++

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* node1 = dummy1;
        ListNode* node2 = dummy2;
        ListNode* node = head;
        int count = 1;
        while (node != NULL) {
            ListNode* tmp = node->next;
            if (count % 2 == 1) {
                node->next = node1->next;
                node1->next = node;
                node1 = node1->next;
            } else {
                node->next = node2->next;
                node2->next = node;
                node2 = node2->next;

            }
            node = tmp;
            ++count;
        }

        node1->next = dummy2->next;

        return dummy1->next;
    }
};
```
