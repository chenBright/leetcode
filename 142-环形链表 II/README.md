# 142-环形链表 II

## 题目

leetcode：[142-环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

## 哈希表

使用哈希表记录遍历过的结点。如果链表存在环，则在遍历到环的入口时，在哈希表中可以找到该结点。

时间复杂度：**O(n)**。
空间复杂度：**O(n)**。

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while (head != NULL) {
            if (s.count(head) != 0) {
                return head;
            }

            s.insert(head);
            head = head->next;
        }

        return NULL;
    }
};
```

## 快慢指针

参考[LeetCode评论区“算法小菜”的思路] (https://leetcode-cn.com/problems/linked-list-cycle-ii/comments/307)和[博客](https://www.cnblogs.com/hiddenfox/p/3408931.html)。

时间复杂度：**O(n)**。
空间复杂度：**O(1)**。

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowP = head;
        ListNode* fastP = head;
        bool flag = false; // 是否存在环
        while (fastP != NULL && fastP->next != NULL) {
            slowP = slowP->next;
            fastP = fastP->next->next;

            if (slowP == fastP) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            return NULL;
        }

        slowP = head;
        while (slowP != fastP) {
            slowP = slowP->next;
            fastP = fastP->next;
        }

        return slowP;
    }
};
```

