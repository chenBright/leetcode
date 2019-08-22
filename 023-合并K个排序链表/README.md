# 23-合并K个排序链表

## 题目

leetcode：[23-合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

## 蛮力法

遍历所有链表，将遍历到的结点逐个插入到新链表中。

```c++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        ListNode *dummy = new ListNode(-1);
        if (lists.empty()) {
            return dummy->next;
        }

        dummy->next = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            ListNode *node = lists[i];
            ListNode *start = dummy; // 开始查找插入位置的其实结点
            while (node != NULL) {
                ListNode *tmp = node;
                node = node->next;
                start = insertToList(start, tmp);
            }
        }

        return dummy->next;
    }
private:
    // 向链表中插入结点（排序）
    // 返回插入结点的指针（相当于位置）
    ListNode* insertToList(ListNode *head, ListNode *node) {
        while (head != NULL && head->next != NULL) {
            if (head->next->val >= node->val) {
                node->next = head->next;
                head->next = node;

                return node;
            }
            head = head->next;
        }

        node->next = head->next;
        head->next = node;

        return node;
    }
};
```

## 取最小的链表头

每次从取出所有链表中最小的头结点，将其插入到新链表尾部。

```c++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        ListNode *dummy = new ListNode(-1);
        if (lists.empty()) {
            return dummy->next;
        }

        ListNode *node = dummy;
        bool flag = true; // 是否有不为空的链表
        while (flag) {
            flag = false;
            ListNode *minNode = new ListNode(INT_MAX); // 记录最小值
            int index; // 记录取出链表头结点的链表索引
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != NULL) {
                    if (lists[i]->val < minNode->val) {
                        minNode = lists[i];
                        index = i;
                    }
                    flag = true;
                }
            }

            if (flag) {
                ListNode *tmp = lists[index];
                lists[index] = lists[index]->next; 
                tmp->next = node->next;
                node->next = tmp;
            }
            node = node->next;
        }

        return dummy->next;
    }
};
```

## 两两合并链表

两两合并链表，直到剩下一个链表为止。

```c++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) {
            return NULL;
        }

        while (lists.size() > 1) {
            vector<ListNode*> tmp;
            int listsLen = lists.size();
            // 两两合并链表
            for (int i = 0; i < listsLen / 2; ++i) {
                tmp.push_back(mergeTwoLists(lists[i], lists[i + listsLen / 2]));
            }
            // 如果链表数为奇数，则最后一个链表轮空，下一循环再合并
            if (listsLen % 2 == 1) {
                tmp.push_back(lists.back());
            }

            lists.swap(tmp);
        }

        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        // 先确定头结点
        ListNode *root = NULL;
        if (l2->val < l1->val) {
            root = l2;
            l2 = l2->next;
        } else {
            root = l1;
            l1 = l1->next;
        }

        ListNode *node = root;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }

        if (l1 == NULL) {
            node->next = l2;
        } else if (l2 == NULL) {
            node->next = l1;
        }

        return root;
    }
};

```

