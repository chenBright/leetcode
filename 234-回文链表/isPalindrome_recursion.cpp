#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// stack 的递归版本
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode **current = &head;
        return helper(head, current);
    }

private:
    // *current 指向链表前面部分，node 指向链表后面部分
    bool helper(ListNode *node, ListNode **current) {
        if (node == NULL) {
            return true;
        }

        // 在递归中，node 一直遍历到最后一个结点。
        // 当第二个 helper() 返回结果后，node 指向倒数第二个结点。
        // 而 *current 则是从第一个结点开始遍历。
        // 该实现有冗余计算，因为 node 只需遍历到中间结点即可，但此处是从第一个结点遍历到最后一个结点。
        // 这样处理有一个好处：不需要处理结点个数奇偶的问题。
        bool result = helper(node->next, current) && (node->val == (*current)->val);
        *current = (*current)->next;

        return result;
    }
};