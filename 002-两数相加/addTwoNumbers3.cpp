#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        int length1 = getLength(l1);
        int length2 = getLength(l2);
        if (length1 < length2) {
            swap(l1, l2);
        }

        // l1 比 l2 长
        ListNode* resultList = l1;
        ListNode* lastNode; // 记录上一结点

        int carry = 0;
        while (l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            l1->val = sum; // 复用 l1 的结点

            lastNode = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (carry == 0) {
            return resultList;
        }

        // l1 比 l2 长，所以只有可能是 l1 没遍历完
        while (l1 != NULL) {
            l1->val += carry;
            if (l1->val >= 10) {
                l1->val -= 10;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
            lastNode = l1;
            l1 = l1->next;
        }

        // 最后还有一个进位需要处理
        if (carry == 1) {
            lastNode->next = new ListNode(1);
        }

        return resultList;
    }

private:
    int getLength(ListNode* l) {
        int length = 0;
        while (l != NULL) {
            ++length;
            l = l->next;
        }

        return length;
    }
};
