#include <utility>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快排
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        pair<ListNode*, ListNode*> nodes = paritition(head);

        ListNode* left = sortList(nodes.first);
        ListNode* right = sortList(nodes.second);

        head->next = right;

        ListNode* leftTail = tail(left);
        if (leftTail != NULL) {
            leftTail->next = head;
            return left;
        } else {
            return head;
        }
    }

private:
    pair<ListNode*, ListNode*> paritition(ListNode* head) {
        if (head == NULL) {
            // 不能使用 NULL
            // 因为在 C++ 中 NULL 的定义为 #define NULL 0，
            // C++ 不允许将整型转换为指针类型。
            return make_pair(nullptr, nullptr);
        }

        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);
        ListNode* node = head->next;
        while (node != NULL) {
            ListNode* tmp = node;
            node = node->next;
            if (tmp->val <= head->val) {
                tmp->next = left->next;
                left->next = tmp;
            } else {
                tmp->next = right->next;
                right->next = tmp;
            }
        }

        return make_pair(left->next, right->next);
    }

    ListNode* tail(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        while (head->next != NULL) {
            head = head->next;
        }

        return head;
    }
};
