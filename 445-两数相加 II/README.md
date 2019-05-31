# 445-两数相加 II

## 题目

leetcode：[445-两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/)

## 使用栈来对齐链表

先使用两个栈来分别保存两个链表的元素，使得两个数字从个位开始对齐，然后按照加法的法则模拟即可。

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

        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        while (l1 != NULL) {
            stack1.push(l1);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            stack2.push(l2);
            l2 = l2->next;
        }

        // 头插法
        ListNode *head = NULL;
        ListNode *node = NULL;
        int carryFlag = 0;
        while (!stack1.empty() && !stack2.empty()) {
            int sum = stack1.top()->val + stack2.top()->val + carryFlag;
            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node = new ListNode(sum);
            node->next = head;
            head = node;
            stack1.pop();
            stack2.pop();
        }

        while (!stack1.empty()) {
            int sum = stack1.top()->val + carryFlag;
            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node = new ListNode(sum);
            node->next = head;
            head = node;
            stack1.pop();
        }

        while (!stack2.empty()) {
            int sum = stack2.top()->val + carryFlag;
            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node = new ListNode(sum);
            node->next = head;
            head = node;
            stack2.pop();
        }

        // 处理最后的进位
        if (carryFlag == 1) {
            node = new ListNode(1);
            node->next = head;
            head = node;
        }

        return head;
    }
};
```

下面的实现更简洁，但是比第一种实现慢。

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

        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        while (l1 != NULL) {
            stack1.push(l1);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            stack2.push(l2);
            l2 = l2->next;
        }

        // 头插法
        ListNode *head = NULL;
        ListNode *node = NULL;
        int carryFlag = 0;
        while (!stack1.empty() || !stack2.empty() || carryFlag == 1) {
            int sum = 0;
            if (!stack1.empty()) {
                sum += stack1.top()->val;
                stack1.pop();
            }
            if (!stack2.empty()) {
                sum += stack2.top()->val;
                stack2.pop();
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
            node = new ListNode(sum);
            node->next = head;
            head = node;
        }

        return head;
    }
};
```

## 递归

先递归计算后面的位，再根据计算结果计算当前的位。

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

        int length1 = 0;
        int length2 = 0;
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        while (node1 != NULL) {
            ++length1;
            node1 = node1->next;
        }
        while (node2 != NULL) {
            ++length2;
            node2 = node2->next;
        }

        bool carryFlag = false;
        ListNode *result = nextNode(l1, length1, l2, length2, &carryFlag);
        
        if (carryFlag) {
            ListNode *node = new ListNode(1);
            node->next = result;
            result = node;
        }

        return result;
    }

private:
    ListNode* nextNode(ListNode *l1, int length1, ListNode *l2, int length2, bool *carryFlag) {
        if (length1 == 0 || length2 == 0) {
            return NULL;
        }

        int sum = 0;
        ListNode *newNode = new ListNode(-1);
        bool lastCarryFlag = false;
        if (length1 > length2) {
            sum = l1->val;
            newNode->next = nextNode(l1->next, --length1, l2, length2, &lastCarryFlag);
        } else if (length1 < length2) {
            sum = l2->val;
            newNode->next = nextNode(l1, length1, l2->next, --length2, &lastCarryFlag);
        } else {
            sum = l1->val + l2->val;
            newNode->next = nextNode(l1->next, --length1, l2->next, --length2, &lastCarryFlag);
        }

        if (lastCarryFlag) {
            sum += 1;
        }

        if (sum >= 10) {
            newNode->val = sum - 10;
            *carryFlag = true;
        } else {
            newNode->val = sum;
            *carryFlag = false;
        }

        return newNode;
    }
};
```