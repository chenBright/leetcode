#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> nodeStack1, nodeStack2;
        convertListToStack(headA, nodeStack1);
        convertListToStack(headB, nodeStack2);

        ListNode *commonNode = NULL; // 共同结点
        while (!nodeStack1.empty() && !nodeStack2.empty()) {
            if (nodeStack1.top() != nodeStack2.top()) {
                break;
            }

            commonNode = nodeStack1.top();
            nodeStack1.pop();
            nodeStack2.pop();
        }

        return commonNode;
    }

private:
    // 将链表转换成栈
    void convertListToStack(ListNode *pHead, stack<ListNode*> &nodeStack) {
        while (pHead != NULL) {
            nodeStack.push(pHead);
            pHead = pHead->next;
        }
    }
};