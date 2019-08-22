#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 蛮力法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        ListNode *dummy = new ListNode(-1);
        if (lists.empty()) {
            return dummy->next;
        }

        dummy->next = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            ListNode *node = lists[i];
            ListNode *start = dummy; // 开始查找插入位置的其实结点
            while (node != NULL) {
                ListNode *tmp = node;
                node = node->next;
                start = insertToList(start, tmp);
            }
        }

        return dummy->next;
    }
private:
    // 向链表中插入结点（排序）
    // 返回插入结点的指针（相当于位置）
    ListNode* insertToList(ListNode *head, ListNode *node) {
        while (head != NULL && head->next != NULL) {
            if (head->next->val >= node->val) {
                node->next = head->next;
                head->next = node;

                return node;
            }
            head = head->next;
        }

        node->next = head->next;
        head->next = node;

        return node;
    }
};
