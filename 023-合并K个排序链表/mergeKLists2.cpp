#include <vector>
#include <limits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        ListNode *dummy = new ListNode(-1);
        if (lists.empty()) {
            return dummy->next;
        }

        ListNode *node = dummy;
        bool flag = true; // 是否有不为空的链表
        while (flag) {
            flag = false;
            ListNode *minNode = new ListNode(INT_MAX); // 记录最小值
            int index; // 记录取出链表头结点的链表索引
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != NULL) {
                    if (lists[i]->val < minNode->val) {
                        minNode = lists[i];
                        index = i;
                    }
                    flag = true;
                }
            }

            if (flag) {
                ListNode *tmp = lists[index];
                lists[index] = lists[index]->next; 
                tmp->next = node->next;
                node->next = tmp;
            }
            node = node->next;
        }

        return dummy->next;
    }
};
