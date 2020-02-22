# 160-相交链表

## 题目

leetcode：[160-相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

## 右对齐两个链表

如果两个链表的长度相等，则我们可以同步遍历这两个链表，找到公共节点。

现在**有两个链表，我们可以先计算两个链表的长度差n，然后长链表的结点指针先偏移offset单位，这样两个链表右对齐后，同步遍历计较两个链表的结点**。

时间复杂度：**O(n+m)**。

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        if (lengthA > lengthB) {
            headA = nextNode(headA, lengthA - lengthB);
        } else if (lengthA < lengthB) {
            headB = nextNode(headB, lengthB - lengthA);
        }

        // 长链表的结点指针先偏移 offset 单位，这样两个链表右对齐后，同步遍历比较两个链表的结点。
        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }

private:
    int getLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            ++length;
            head = head->next;
        }

        return length;
    }

    ListNode* nextNode(ListNode* node, int step) {
        for (int i = 0; i < step && node != NULL; ++i) {
            node = node->next;
        }

        return node;
    }
};
```

## 使用栈实现右对齐两个链表

使用栈实现右对齐两个链表后，从链表尾开始遍历比较两个链表的结点，找到“最后一个共同结点”，即原链表的第一个共同结点。

时间复杂度：**O(n+m)**。

```c++
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> nodeStack1, nodeStack2;
        convertListToStack(headA, nodeStack1);
        convertListToStack(headB, nodeStack2);

        ListNode *commonNode = NULL; // 共同结点
        while (!nodeStack1.empty() && !nodeStack2.empty()) {
            if (nodeStack1.top() != nodeStack2.top()) {
                break;
            }

            commonNode = nodeStack1.top();
            nodeStack1.pop();
            nodeStack2.pop();
        }

        return commonNode;
    }

private:
    // 将链表转换成栈
    void convertListToStack(ListNode *pHead, stack<ListNode*> &nodeStack) {
        while (pHead != NULL) {
            nodeStack.push(pHead);
            pHead = pHead->next;
        }
    }
};
```

## 使用unordered_set记录一个链表的结点

使用`unordered_set`记录一个链表的结点，然后遍历另一个链表，查找该链表的结点是否在`unordered_set`中，第一个在`unordered_set`中的结点即为第一个共同结点。

时间复杂度：**O(n+m)**。

```c++
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while (headA != NULL) {
            s.insert(headA);
            headA = headA->next;
        }

        while (headB != NULL) {
            if (s.count(headB) != 0) {
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
};
```

## 巧妙的解法

参考[LeetCode评论区 SEU.FidGet 的解法](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/comments/3107)。

时间复杂度：**O(n+m)**。

```c++
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *pA = headA;
        ListNode *pB = headB;
        /**
         * 在这里第一轮体现在pA和pB第一次到达尾部会移向另一链表的表头,
         * 而第二轮体现在如果pA或pB相交就返回交点, 不相交最后就是null==null
         */
        while (pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }

        return pA;
    }
};
```

