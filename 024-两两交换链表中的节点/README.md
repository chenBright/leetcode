# 024-两两交换链表中的节点

## 题目

leetcode：[024-两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)


## 迭代

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1); // 设置一个前置结点，这样可以不用专门处理头结点无“前结点”的情况
        dummy->next = head;
        ListNode *preNode = dummy;
        ListNode *curNode = head;
        while (curNode != NULL && curNode->next != NULL) {
            // 交换
            preNode->next = curNode->next;
            curNode->next = curNode->next->next;
            preNode->next->next = curNode;

            preNode = curNode;
            curNode = curNode->next;
        }

        return dummy->next;
    }
};
```

## 递归

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *newHead = head->next;
        ListNode *node = head->next->next;
        // 交换结点
        newHead->next = head;
        head->next = swapPairs(node); // 防止断链

        return newHead;
    }
};
```

