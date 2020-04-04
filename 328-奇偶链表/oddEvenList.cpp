#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* node1 = dummy1;
        ListNode* node2 = dummy2;
        ListNode* node = head;
        int count = 1;
        while (node != NULL) {
            ListNode* tmp = node->next;
            if (count % 2 == 1) {
                node->next = node1->next;
                node1->next = node;
                node1 = node1->next;
            } else {
                node->next = node2->next;
                node2->next = node;
                node2 = node2->next;

            }
            node = tmp;
            ++count;
        }

        node1->next = dummy2->next;

        return dummy1->next;
    }
};