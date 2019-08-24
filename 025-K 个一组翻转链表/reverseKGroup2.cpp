#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;


        ListNode *previous = dummy;
        ListNode *end = dummy;
        while (end->next != NULL) {
            for (int i = 0; i < k && end != NULL; ++i) {
                end = end->next;
            }

            if (end == NULL) {
                break;
            }

            ListNode *current = previous->next;
            ListNode *oldStart = current; // 未翻转前的第一个结点
            ListNode *nextStart = end->next;
            // 翻转
            for (int i = k; i > 0; --i) {
                ListNode *next = current->next;
                current->next = previous;
                previous = current;
                current = next;
                if (next != NULL) {
                    next = next->next;
                }
            }
            // 翻转后，oldStart 结点变成最后一个结点。
            // 翻转部分的前一个结点 oldStart->next 的 next 域指向翻转后的第一个结点（现 previous）。
            // 翻转后的最后一个结点 oldStart 的 next 域指向 current，则 previous 指向 oldStart。
            oldStart->next->next = previous;
            oldStart->next = current;
            previous = oldStart;
            
            end = previous; // 更新 end 指针
        }

        return dummy->next;
    }
};