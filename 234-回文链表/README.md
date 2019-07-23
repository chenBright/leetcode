# 234-回文链表

## 题目

leetcode：[234-回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)

## 用数组保存结点的值

使用数组保存结点的值，然后在数组首尾开始对比元素值即可。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }

        // 前后逐一对比
        int left = 0;
        int right = v.size() - 1;
        while (left < right) {
            if (v[left] != v[right]) {
                return false;
            }
            ++left;
            --right;
        }
        
        return true;
    }
};
```

## 使用栈保存结点的值

使用栈保存结点的值，再从链表头开始，一一与栈中的值对比。

其实，不需要保存整个链表的值，只需要保存前面一半的值即可。可以使用快慢指针，找到前面一般的值。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

### 迭代

```c++
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        stack<int> s;

        ListNode *fast = head; // 快指针
        ListNode *slow = head; // 慢指针
        while (fast != NULL && fast->next != NULL) {
            s.push(slow->val); // 将前一半的结点的值压入栈中
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow 指向第 n / 2 + 1 个结点。
        // 链表结点个数为偶数，fast 指向 NULL，此时 slow 刚刚好指向链表后一半的第一个结点。
        // 链表结点个数为奇数，fast->next 指向 NULL，此时 slow 刚刚好指向链表的中间结点。
        ListNode *ptr = fast == NULL ? slow : slow->next;

        // 链表后半部分和栈中元素逐一对比
        while (!s.empty()) {
            if (s.top() != ptr->val) {
                return false;
            }
            s.pop();
            ptr = ptr->next;
        }
        
        return true;
    }
};
```

### 递归

可以利用递归调用的调用栈来代替`stack`。

```c++
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode **current = &head;
        return helper(head, current);
    }

private:
    // *current 指向链表前面部分，node 指向链表后面部分
    bool helper(ListNode *node, ListNode **current) {
        if (node == NULL) {
            return true;
        }

        // 在递归中，node 一直遍历到最后一个结点。
        // 当第二个 helper() 返回结果后，node 指向倒数第二个结点。
        // 而 *current 则是从第一个结点开始遍历。
        // 该实现有冗余计算，因为 node 只需遍历到中间结点即可，但此处是从第一个结点遍历到最后一个结点。
        // 这样处理有一个好处：不需要处理结点个数奇偶的问题。
        bool result = helper(node->next, current) && (node->val == (*current)->val);
        *current = (*current)->next;

        return result;
    }
};
```

## 使用快慢指针翻转链表前一半，再前后对比

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL) {
            return true;
        }

        ListNode *fast = head->next; // 快指针
        ListNode *slow = head; // 慢指针
        ListNode *previous = NULL;
        ListNode *next = NULL;
        // 翻转前一半的结点
        while (fast != NULL && fast->next != NULL) {
            next = slow->next;
            slow->next = previous;
            previous = slow;
            slow = next;

            fast = fast->next->next;
        }

        // 该实现与 isPalindrome_stack.cpp 的实现不一样。
        // 该实现中，fast = head->next。
        // slow 指向第 n / 2 + 1 个结点
        // 链表结点个数为奇数，fast 指向 NULL，此时 slow 刚刚好指向链表前一半的最后一个结点。
        // 链表结点个数为偶数，fast->next 指向 NULL，此时 slow 刚刚好指向链表的中间结点。
        // 综上，slow->next 都是指向链表后一半的第一个结点。
        ListNode *back = slow->next;
        slow->next = previous;
        ListNode *front = fast == NULL ? slow->next : slow;
        while (front != NULL && back != NULL) {
            if (front->val != back->val) {
                return false;
            }
            front = front->next;
            back = back->next;
        }
        
        return true;
    }
};
```

