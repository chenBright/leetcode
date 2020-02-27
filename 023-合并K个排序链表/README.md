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

## 排序

将结点的值保存到数组中，再对数组排序，最后从数组中依次取值新建结点，并插入到新链表末尾。

```c++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) {
            return NULL;
        }

        vector<int> v;
        for (const auto &list : lists) {
            ListNode *node = list;
            while (node != NULL) {
                v.push_back(node->val);
                node = node->next;
            }
        }

        sort(v.begin(), v.end());

        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        for (int i = 0; i < v.size(); ++i) {
            current->next = new ListNode(v[i]);
            current = current->next;
        }

        return dummy->next;
    }
};
```

## 取最小的链表头

每次从取出所有链表中最小的头结点，将其插入到新链表尾部。

```c++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        ListNode* dummy = new ListNode(INT_MAX);
        ListNode* lastNode = dummy; // 归并后的链表的最后一个结点
        int length = lists.size();
        while (true) {
            ListNode* minNode = dummy; // k 个链表中值最下的结点
            int listIndex = -1;
            for (int i = 0; i < length; ++i) {
                if (lists[i] != NULL && lists[i]->val < minNode->val) {
                    minNode = lists[i];
                    listIndex = i;
                }
            }

            if (listIndex == -1) {
                break;
            }

            lists[listIndex] = lists[listIndex]->next;
            // 插入到新链表
            minNode->next = lastNode->next;
            lastNode->next = minNode;
            lastNode = lastNode->next;
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

可以不使用辅助数组，原地即可合并链表。

参考[912-排序数组](./912-排序数组/README.md#迭代实现自底向上)中非递归归并排序的归并思路。

```c++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        int length = lists.size();
        // 非递归归并排序的归并思路
        for (int interval = 1; interval < length; interval *= 2) { // 间隔
            for (int i = 0; i < length - interval; i += 2 * interval) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
        }

        return lists[0];
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* lastNode = dummy;
        while (l1 != NULL && l2 != NULL) {
            ListNode* node = NULL;
            if (l1->val < l2->val) {
                node = l1;
                l1 = l1->next;
            } else {
                node = l2;
                l2 = l2->next;
            }
            node->next = dummy->next;
            lastNode->next = node;
            lastNode = lastNode->next;
        }

        if (l1 != NULL) {
            lastNode->next = l1;
        }
        if (l2 != NULL) {
            lastNode->next = l2;
        }

        return dummy->next;
    }
};
```

## 优先队列

参考[博客解法二](https://github.com/grandyang/leetcode/issues/23)。

将链表的头结点放入到优先队列中，每次从优先队列中取出最小值的结点，插入到新链表中。同时，将取出的结点的下一个结点放入到优先队列中，知道链表为空。

循环以上过程，直到优先队列为空。

```c++
class Solution {
public:
    struct compare {
        // 上浮操作
        // a：父结点
        // b：子结点
        // 返回 true，则上浮结点
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*> &lists) {
        // 小堆
        priority_queue<ListNode*, vector<ListNode*>, compare> q;

        for (const auto &node : lists) {
            if (node != NULL) {
                q.push(node);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        while (!q.empty()) {
            ListNode *tmp = q.top();
            q.pop();
            current->next = tmp;
            current = current->next;
            if (tmp->next != NULL) {
                q.push(tmp->next);
            }
        }

        return dummy->next;
    }
};
```

