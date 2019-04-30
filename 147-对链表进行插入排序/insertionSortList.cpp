#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode *head) {
        if (head == NULL) {
            return head;
        }

        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *frontNode = newHead; // 待插入的结点的前一个结点指针
        ListNode *node = newHead->next; // 待插入的结点指针
        while (node != NULL) {
            ListNode *indexFrontNode = newHead; // 用于遍历的结点的前一个结点指针
            ListNode *indexNode = newHead->next; // 用于遍历的结点指针
            while (indexNode != node) {
                // 找到第一个不小于 node 的结点
                if (indexNode->val >= node->val) {
                    frontNode->next = node->next; // 将 node 取出
                    // 插入 node
                    node->next = indexNode;
                    indexFrontNode->next = node;
                    // 更新待插入的结点指针
                    node = frontNode->next;
                    break;
                }
                indexFrontNode = indexNode;
                indexNode = indexNode->next;
            }
            // 如果没有插入到前面，则移动待插入结点指针
            if (indexNode == node) {
                frontNode = node;
                node = node->next;
            }
        }

        return newHead->next;
    }
};