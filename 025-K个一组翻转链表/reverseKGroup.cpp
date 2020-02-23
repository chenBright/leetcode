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

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* preNode = dummy; // 分组的前一个结点
        while (head != NULL) {
            ListNode* left = head;
            // 注意 k - 1
            for (int i = 0; i < k - 1 && head != NULL; ++i) {
                head = head->next;
            }

            if (head == NULL) {
                break;
            }

            ListNode* nextPreNode = left;
            ListNode* right = head;
            head = head->next;

            // 翻转后，返回新分组的第一个结点，用分组的前一个结点指向新分组。
            preNode->next = reverse(left, right);

            // 更新分组的前一个结点
            preNode = nextPreNode;
        }

        return dummy->next;
    }

private:
    // 翻转后，返回新分组的第一个结点
    ListNode* reverse(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        // 分组后面一个结点，用作循环结束条件
        ListNode* end = right->next;
        // 分组最后一个结点指向 end 结点。
        // 因为使用头插法插入结点，所以此时分组已经重新连接上原来的链表中。
        dummy->next = end;
        while (left != end) {
            ListNode* tmp = left;
            left = left->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }

        return dummy->next;
    }
};