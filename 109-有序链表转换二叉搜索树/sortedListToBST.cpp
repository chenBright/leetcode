#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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