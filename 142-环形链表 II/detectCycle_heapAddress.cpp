#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 堆的地址从低到高，LeetCode的链表内存是顺序申请的
// 存在node->next的内存地址小于node的内存地址
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *node = head;
        // 计较内存地址
        auto heapAddressCompare = less<ListNode*>();
        while (node != NULL) {
            // next 结点的内存地址比 node 结点的小，表示 next 结点为环的第一个结点
            if (!heapAddressCompare(node, node->next)) {
                return node->next;
            }
            node = node->next;
        }

        return NULL;
    }
};
