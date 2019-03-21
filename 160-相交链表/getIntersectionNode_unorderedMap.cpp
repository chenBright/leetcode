#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> nodeMap;

        while (headA != NULL) {
            nodeMap.insert(make_pair(headA, 1));
            headA = headA->next;
        }

        while (headB != NULL) {
            if (nodeMap.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
};