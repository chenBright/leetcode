#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        int index = 1;
        ListNode *node = head;
        ListNode *beforreStartNode = dummy; // 位置 m - 1上的结点
        // 找到第一个反转的结点，即位置 m 上的结点
        while (index < m && node != NULL) {
            beforreStartNode = node;
            node = node->next;
            ++index;
        }

        ListNode *end = node;
        node = node->next;
        ++index;
        // 反转
        while (index <= n && node != NULL) {
            ListNode *tmpNode = node;
            node = node->next;

            tmpNode->next = beforreStartNode->next;
            beforreStartNode->next = tmpNode;
            ++index;
        }
        // 此时 node 指向位置 n + 1，即最后一个反转结点后面一个结点
        end->next = node;

        return dummy->next;
    }
};
