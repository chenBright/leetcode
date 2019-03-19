# 141-环形链表

## 题目

leetcode：[141-环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

## 快慢指针

- 快指针：每次"走两步"
- 慢指针：每次"走一次"

如果遍历到两个我指针其中一个指向`NULL`，则表示不是环形链表；否则，快指针在环形链表中会"追上"慢指针，即`pFast == pSlow`。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next) {
            return false;
        }

        ListNode *pSlow = head->next; // 慢指针
        ListNode *pFast = pSlow->next; // 快指针

        while (pSlow != NULL && pFast != NULL) {
            if (pSlow == pFast) {
                return true;
            }

            pSlow = nextNode(pSlow, 1);
            pFast = nextNode(pFast, 2);
        }

        return false;
    }

private:
    // 下一结点
    ListNode* nextNode(ListNode* node, int step) {
        for (int i = 0; i < step && node != NULL; ++i) {
            node = node->next;
        }

        return node;
    }
};
```