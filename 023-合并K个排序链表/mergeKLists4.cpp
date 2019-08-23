#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 优先队列（最小堆）
class Solution {
public:
    struct compare {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;

        for (const auto &node : lists) {
            if (node != NULL) {
                q.push(node);
            }
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        while (!q.empty()) {
            ListNode *tmp = q.top();
            q.pop();
            current->next = tmp;
            current = current->next;
            if (tmp->next != NULL) {
                q.push(tmp->next);
            }
        }

        return dummy->next;
    }
};
