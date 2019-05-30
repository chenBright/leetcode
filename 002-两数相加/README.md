# 002-两数相加

## 题目

leetcode：[002-两数相加](https://leetcode-cn.com/problems/two-sum/)


## 直接模拟加法

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *head = new ListNode(-1);
        ListNode *node = head;
        bool carryFlag = false;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carryFlag;
            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            int sum = l1->val + carryFlag;
            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum =l2->val + carryFlag;
            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node->next = new ListNode(sum);
            node = node->next;
            l2 = l2->next;
        }

        // 处理最后的进位
        if (carryFlag == 1) {
            node->next = new ListNode(1);
        }

        return head->next;
    }
};
```

下面的实现更简洁，但是比第一种实现慢。

```c++
lass Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *head = new ListNode(-1);
        ListNode *node = head;
        int carryFlag = 0;
        while (l1 != NULL || l2 != NULL || carryFlag == 1) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carryFlag == 1) {
                sum += 1;
            }

            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node->next = new ListNode(sum);
            node = node->next;
        }

        return head->next;
    }
};
```

