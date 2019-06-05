# 142-环形链表 II

## 题目

leetcode：[142-环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

## 快慢指针 + Set

先使用快慢指针的方法检测链表是否有环：

- 如果没有，返回`NULL`。
- 如果有，再遍历一次链表，并将结点指针保存到`Set`中。如果遍历过程中，结点指针已经在`Set`中，则该结点即为环的第一个结点。

该方法的时间复杂度为***O(n)***，空间复杂度为***O(n)***。

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!hasCycle(head)) {
            return NULL;
        }

        unordered_set<ListNode*> nodeSet;
        ListNode *node = head;
        while (nodeSet.find(node) == nodeSet.end()) {
            nodeSet.insert(node);
            node = node->next;
        }

        return node;
    }

private:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *pSlow = head->next; // 慢指针
        ListNode *pFast = pSlow->next; // 快指针

        while (pFast != NULL && pFast->next != NULL) {
            if (pSlow == pFast) {
                return true;
            }

            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        return false;
    }
};
```

## 比较堆地址

堆的地址从低到高，LeetCode的链表内存是顺序申请的，所以

- 如果链表没有环，`node->next`的内存地址一定大于`node`的内存地址。
- 如果有环，存在`node->next`的内存地址小于`node`的内存地址。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *node = head;
        // 计较内存地址
        auto heapAddressCompare = less<ListNode*>();
        while (node != NULL) {
            // next 结点的内存地址比 node 结点的小，表示 next 结点为环的第一个结点
            if (!heapAddressCompare(node, node->next)) {
                return node->next;
            }
            node = node->next;
        }

        return NULL;
    }
};
```

## 快慢指针 + 双指针

参考[LeetCode评论区 算法小菜 的思路] (https://leetcode-cn.com/problems/linked-list-cycle-ii/comments/307)和[网上大神的思路](https://www.cnblogs.com/hiddenfox/p/3408931.html)。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *pSlow = head->next; // 慢指针
        ListNode *pFast = pSlow->next; // 快指针

        bool hasCycle = false;
        while (pFast != NULL && pFast->next != NULL) {
            if (pSlow == pFast) {
                hasCycle = true;
                break;
            }

            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        if (!hasCycle) {
            return NULL;
        }

        pFast = head; // 复用快指针
        while (pFast != pSlow) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }

        return pSlow;
    }

};
```

