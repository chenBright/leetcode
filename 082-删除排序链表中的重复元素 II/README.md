# 082-删除排序链表中的重复元素 II

## 题目

leetcode：[082-删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)


## 思路

新建一个`dummy`结点，接到链表头，用于记录链表头。使用指针`preNode`记录删除后的链表的最后一个结点，指针`curNode`用于遍历链表。还需要一个变量`hasEqual`来记录遍历过程中是否存在重复的元素。

- 当***curNode->val == curNode->next->val***时，则***hasEqual = true***，继续遍历下一个结点。
- 当***curNode->val != curNode->next->val***时：
  - 如果***hasEqual == false***，即没有重复的元素，则`preNode`和`curNode`都向后移动一个结点。
  - 如果***hasEqual == true***，即有重复的元素，则`preNode->next`和`curNode`都指向`curNode->next`，删除重复的元素。

存在一种情况在循环里没有处理——链表的几个元素是重复的元素，例如***[1,2,3,4]***。则在循环结束后，如果***hasEqual == true***，表示链表的几个元素是重复的元素，则直接令`preNode->next`指向`NULL`。

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode *preNode = dummy;
        ListNode *curNode = head;
        bool hasEqual = false; // 是否存在重复的元素
        while (curNode != NULL && curNode->next != NULL) {
            if (curNode->val == curNode->next->val) {
                curNode = curNode->next;
                hasEqual = true;
            } else {
                if (hasEqual) {
                    preNode->next = curNode->next;
                    curNode->next = NULL;
                    curNode = preNode->next;
                } else {
                    preNode = curNode;
                    curNode = curNode->next;
                }
                hasEqual = false;
            }
        }

        // 如果最后的元素为重复的元素，如 [1,2,3,3]，这些元素未在循环中处理
        if (hasEqual) {
            preNode->next = NULL;
        }

        return dummy->next;
    }
};
```

