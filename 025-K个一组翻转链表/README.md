# 025-K个一组翻转链表

## 题目

leetcode：[025-K个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

## 思路

解题的关键是：对一个组翻转后，原来首尾的结点的位置互换，即原组内第一个结点变成组内最后一个结点，原组内最后一个结点变成第一个结点。处理好这个问题，就能解决这道题了。

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

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* preNode = dummy; // 分组的前一个结点
        while (head != NULL) {
            ListNode* left = head;
            // 注意 k - 1
            for (int i = 0; i < k - 1 && head != NULL; ++i) {
                head = head->next;
            }

            if (head == NULL) {
                break;
            }

            ListNode* right = head;
            head = head->next;
            // 翻转后，right 变成分组的第一个结点，用分组的前一个结点指向 right。
            preNode->next = right;
            // 更新
            preNode = left;

            reverse(left, right);
        }

        return dummy->next;
    }

private:
    void reverse(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        // 分组后面一个结点，用作循环结束条件
        ListNode* end = right->next;
        // 分组最后一个结点指向 end 结点。
        // 因为使用头插法插入结点，所以此时分组已经重新连接上原来的链表中。
        dummy->next = end;
        while (left != end) {
            ListNode* tmp = left;
            left = left->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
    }
};
```

