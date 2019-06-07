#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        ListNode *node1 = head; // 慢指针
        ListNode *node2 = head; // 快指针
        while (node2 != NULL && node2->next != NULL) {
            node1 = node1->next;
            node2 = node2->next->next;
        }

        // 反转后半部分链表
        // 如果链表长度为偶数，则 neededReverseNode 指向第 n / 2 + 1 的结点
        // 如，1 -> 2 -> 3 -> 4 -> 5 -> 6
        // neededReverseNode 指向 5，因为 4 重排之后也在 3 后面，所以不需要处理
        // 这样，刚好不用处理奇偶数的问题
        ListNode *neededReverseNode = node1->next;
        node1->next = NULL;
        ListNode *preNode = NULL;
        ListNode *postNode = neededReverseNode;
        while (neededReverseNode != NULL && postNode != NULL) {
            postNode = postNode->next;
            neededReverseNode->next = preNode;
            preNode = neededReverseNode;
            neededReverseNode = postNode;
        }

        // 重排链表
        neededReverseNode = preNode;
        while (neededReverseNode != NULL) {
            preNode = neededReverseNode;
            neededReverseNode = neededReverseNode->next;

            preNode->next = head->next;
            head->next = preNode;
            head = head->next->next;
        }
    }
};