#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while (head != NULL) {
            if (s.count(head) != 0) {
                return head;
            }

            s.insert(head);
            head = head->next;
        }

        return NULL;
    }
};
