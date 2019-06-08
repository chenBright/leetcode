#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
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