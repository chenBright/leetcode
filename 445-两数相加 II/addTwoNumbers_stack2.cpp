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

        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        while (l1 != NULL) {
            stack1.push(l1);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            stack2.push(l2);
            l2 = l2->next;
        }

        // 头插法
        ListNode *head = NULL;
        ListNode *node = NULL;
        int carryFlag = 0;
        while (!stack1.empty() || !stack2.empty() || carryFlag == 1) {
            int sum = 0;
            if (!stack1.empty()) {
                sum += stack1.top()->val;
                stack1.pop();
            }
            if (!stack2.empty()) {
                sum += stack2.top()->val;
                stack2.pop();
            }
            if (carryFlag == 1) {
                sum += 1;
            }
            if (sum >= 10) {
                sum -= 10;
                carryFlag = 1;
            } else {
                carryFlag = 0;
            }
            node = new ListNode(sum);
            node->next = head;
            head = node;
        }

        return head;
    }
};