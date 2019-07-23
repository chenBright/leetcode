#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        stack<int> s;

        ListNode *fast = head; // 快指针
        ListNode *slow = head; // 慢指针
        while (fast != NULL && fast->next != NULL) {
            s.push(slow->val); // 将前一半的结点的值压入栈中
            fast = fast->next->next;
            slow = slow->next;
        }

        // slow 指向第 n / 2 + 1 个结点。
        // 链表结点个数为偶数，fast 指向 NULL，此时 slow 刚刚好指向链表后一半的第一个结点。
        // 链表结点个数为奇数，fast->next 指向 NULL，此时 slow 刚刚好指向链表的中间结点。
        ListNode *ptr = fast == NULL ? slow : slow->next;

        // 链表后半部分和栈中元素逐一对比
        while (!s.empty()) {
            if (s.top() != ptr->val) {
                return false;
            }
            s.pop();
            ptr = ptr->next;
        }
        
        return true;
    }
};