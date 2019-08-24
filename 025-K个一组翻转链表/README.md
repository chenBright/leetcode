# 025-K个一组翻转链表

## 题目

leetcode：[025-K个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

## 思路

解题的关键是：对一个组翻转后，原来首尾的结点的位置互换，即原组内第一个结点编程组内最后一个结点，原组内最后一个结点变成第一个结点。处理好这个问题，就能解决这道题了。

### 先根据链表长度分好组，然后对每组进行翻转

```c++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        int length = getLength(head);
        int count = length / k;

        ListNode *current = head;
        ListNode *previous = dummy;
        ListNode *next = head->next;
        while (count > 0) {
            ListNode *oldStart = current; // 未翻转前的第一个结点
            // 翻转
            for (int i = k; i > 0; --i) {
                current->next = previous;
                previous = current;
                current = next;
                if (next != NULL) {
                    next = next->next;
                }
            }
            // 翻转后，oldStart 结点变成最后一个结点
            // 翻转部分的前一个结点 oldStart->next 的 next 域指向翻转后的第一个结点（现 previous）
            // 翻转后的最后一个结点 oldStart 的 next 域指向 current，则 previous 指向 oldStart
            oldStart->next->next = previous;
            oldStart->next = current;
            previous = oldStart;
            --count;
        }

        return dummy->next;
    }
private:
    // 计算链表长度
    int getLength(ListNode *head) {
        int count = 0;
        while (head != NULL) {
            ++count;
            head = head->next;
        }

        return count;
    }
};
```

### 分出一个分组后，立即进行翻转

参考[LeetCode题解](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/kge-yi-zu-fan-zhuan-lian-biao-by-powcai/)。

下图为反转的过程（图来自[LeetCode题解](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/kge-yi-zu-fan-zhuan-lian-biao-by-powcai/)，侵删）。

![img](/Users/chenbright/Desktop/c:c++_workspace/leetcode/025-K 个一组翻转链表/img.png)

```c++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;


        ListNode *previous = dummy;
        ListNode *end = dummy;
        while (end->next != NULL) {
            for (int i = 0; i < k && end != NULL; ++i) {
                end = end->next;
            }

            if (end == NULL) {
                break;
            }

            ListNode *current = previous->next;
            ListNode *oldStart = current; // 未翻转前的第一个结点
            ListNode *nextStart = end->next;
            // 翻转
            for (int i = k; i > 0; --i) {
                ListNode *next = current->next;
                current->next = previous;
                previous = current;
                current = next;
                if (next != NULL) {
                    next = next->next;
                }
            }
            // 翻转后，oldStart 结点变成最后一个结点。
            // 翻转部分的前一个结点 oldStart->next 的 next 域指向翻转后的第一个结点（现 previous）。
            // 翻转后的最后一个结点 oldStart 的 next 域指向 current，则 previous 指向 oldStart。
            oldStart->next->next = previous;
            oldStart->next = current;
            previous = oldStart;
            
            end = previous; // 更新 end 指针
        }

        return dummy->next;
    }
};
```

