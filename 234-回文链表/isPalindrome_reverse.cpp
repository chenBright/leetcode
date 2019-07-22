#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL) {
            return true;
        }

        ListNode *fast = head->next; // 快指针
        ListNode *slow = head; // 慢指针
        ListNode *previous = NULL;
        ListNode *next = NULL;
        // 翻转前一半的结点
        while (fast != NULL && fast->next != NULL) {
            next = slow->next;
            slow->next = previous;
            previous = slow;
            slow = next;

            fast = fast->next->next;
        }

        // 该实现与 isPalindrome_stack.cpp 的实现不一样。
        // 该实现中，fast = head->next。
        // slow 指向第 n / 2 + 1 个结点
        // 链表结点个数为奇数，fast 指向 NULL，此时 slow 刚刚好指向链表前一半的最后一个结点。
        // 链表结点个数为偶数，fast->next 指向 NULL，此时 slow 刚刚好指向链表的中间结点。
        // 综上，slow->next 都是指向链表后一半的第一个结点。
        ListNode *back = slow->next;
        slow->next = previous;
        ListNode *front = fast == NULL ? slow->next : slow;
        while (front != NULL && back != NULL) {
            if (front->val != back->val) {
                return false;
            }
            front = front->next;
            back = back->next;
        }
        
        return true;
    }
};