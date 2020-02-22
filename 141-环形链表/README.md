# 141-环形链表

## 题目

leetcode：[141-环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

## 哈希表

使用哈希表记录遍历过的结点。如果链表存在环，则在遍历到环的入口时，在哈希表中可以找到该结点。

时间复杂度为**O(n)**。

空间复杂度为**O(n)**。

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while (head != NULL) {
            if (s.count(head) != 0) {
                return true;
            }

            s.insert(head);
            head = head->next;
        }

        return false;
    }
};
```

## 快慢指针

- 快指针：每次"走两步"
- 慢指针：每次"走一步"

如果遍历到两个我指针其中一个指向`NULL`，则表示不是环形链表；否则，快指针在环形链表中会"追上"慢指针，即`pFast == pSlow`。

时间复杂度为**O(n)**。

空间复杂度为**O(1)**。

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slowP = head;
        ListNode* fastP = head;
        while (fastP != NULL && fastP->next != NULL) {
            slowP = slowP->next;
            fastP = fastP->next->next;

            if (slowP == fastP) {
                return true;
            }
        }

        return false;
    }
};
```