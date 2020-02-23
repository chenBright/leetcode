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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        ListNode* dummy = new ListNode(INT_MAX);
        ListNode* lastNode = dummy; // 归并后的链表的最后一个结点
        int length = lists.size();
        while (true) {
            ListNode* minNode = dummy; // k 个链表中值最下的结点
            int listIndex = -1;
            for (int i = 0; i < length; ++i) {
                if (lists[i] != NULL && lists[i]->val < minNode->val) {
                    minNode = lists[i];
                    listIndex = i;
                }
            }

            if (listIndex == -1) {
                break;
            }

            lists[listIndex] = lists[listIndex]->next;
            // 插入到新链表
            minNode->next = lastNode->next;
            lastNode->next = minNode;
            lastNode = lastNode->next;
        }

        return dummy->next;
    }
};
