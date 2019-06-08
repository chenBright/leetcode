#include <deque>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        // 使用双端队列保存结点
        deque<ListNode*> nodeDeque;
        while (head != NULL) {
            nodeDeque.push_back(head);
            head = head->next;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *curNode = dummy;
        while (!nodeDeque.empty()) {
            curNode->next = nodeDeque.front();
            nodeDeque.pop_front();
            curNode = curNode->next;
            if (!nodeDeque.empty()) {
                curNode->next = nodeDeque.back();
                nodeDeque.pop_back();
                curNode = curNode->next;
            }
        }
        // 处理链表尾，不然重排后的链表会出现“环”，
        // LeetCode 验证结果的时候出现死循环，最后导致超出时间限制
        curNode->next = NULL;
    }
};