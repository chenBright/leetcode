# 109-有序链表转换二叉搜索树

## 题目

leetcode：[109-有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

## 思路1

将有序链表转换成有序数组，然后使用[108-将有序数组转换为二叉搜索树](../108-将有序数组转换为二叉搜索树/)的方法构建高度平衡的二叉搜索树。

## 思路2

直接使用链表构建高度平衡的二叉搜索树：

1. 选取链表中间的结点作为根结点。
2. 根结点左边部分作为左子树，右边部分作为右子树。

递归执行步骤1、2。

查找数组中间结点使用***快慢指针***的方法。

```c++
class Solution {
public:
    TreeNode* sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        return sortedListToBST(head, NULL);
    }

private:
    // 使用快慢指针找出 [begin, end) 范围内的中间结点
    ListNode* getMidNode(ListNode *begin, ListNode *end) {
        if (begin == NULL) {
            return NULL;
        }

        ListNode *fast = begin;
        ListNode *slow = begin;
        while (fast != end && fast->next != end && slow != end) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    // 将 [begin, end) 范围内的结点，构建成一颗高度平衡的二叉搜索树
    TreeNode* sortedListToBST(ListNode *begin, ListNode *end) {
        if (begin == NULL || begin == end) {
            return NULL;
        }

        ListNode *midNode = getMidNode(begin, end);
        if (midNode == NULL) {
            return NULL;
        }

        TreeNode *root = new TreeNode(midNode->val);
        root->left = sortedListToBST(begin, midNode);
        root->right = sortedListToBST(midNode->next, end);

        return root;
    }
};
```



