# 203-移除链表元素

## 题目

leetcode：[203-移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)

## 迭代

找到值等于`val`的结点后，继续往后找，直到值不等于`val`为止，然后将该部分移除。

```c++
class Solution {
public:
    ListNode* removeElements(ListNode *head, int val) {
        if (head == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curNode = dummy;
        ListNode *nextNode = curNode->next;
        while (curNode != NULL && nextNode != NULL) {
            if (nextNode->val == val) {
                while (nextNode != NULL && nextNode->val == val) {
                    nextNode = nextNode->next;
                }
                curNode->next = nextNode;
            } else {
                curNode = curNode->next;
                nextNode = nextNode->next;
            }
        }

        return dummy->next;
    }
};
```

## 递归

- 先递归移除后面的元素
- 如果当前结点的值等于`val`，则返回`next`结点；否则，返回当前结点。

```c++
class Solution {
public:
    ListNode* removeElements(ListNode *head, int val) {
        if (head == NULL) {
            return head;
        }

        head->next = removeElements(head->next, val);

        return head->val == val ? head->next : head;
    }
};
```