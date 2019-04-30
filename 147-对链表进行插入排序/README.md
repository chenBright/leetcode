# 147-对链表进行插入排序

## 题目

leetcode：[147-对链表进行插入排序](https://leetcode-cn.com/problems/insertion-sort-list/)

## 数组

先将链表转化为数组，这样做插入排序就很方便了。

代码略。

## 链表

直接对链表进行插入排序，关键点在于要使用一个指针保存结点的前一个结点的位置。

```c++
class Solution {
public:
    ListNode* insertionSortList(ListNode *head) {
        if (head == NULL) {
            return head;
        }

        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *frontNode = newHead; // 待插入的结点的前一个结点指针
        ListNode *node = newHead->next; // 待插入的结点指针
        while (node != NULL) {
            ListNode *indexFrontNode = newHead; // 用于遍历的结点的前一个结点指针
            ListNode *indexNode = newHead->next; // 用于遍历的结点指针
            while (indexNode != node) {
                // 找到第一个不小于 node 的结点
                if (indexNode->val >= node->val) {
                    frontNode->next = node->next; // 将 node 取出
                    // 插入 node
                    node->next = indexNode;
                    indexFrontNode->next = node;
                    // 更新待插入的结点指针
                    node = frontNode->next;
                    break;
                }
                indexFrontNode = indexNode;
                indexNode = indexNode->next;
            }
            // 如果没有插入到前面，则移动待插入结点指针
            if (indexNode == node) {
                frontNode = node;
                node = node->next;
            }
        }

        return newHead->next;
    }
};
```

