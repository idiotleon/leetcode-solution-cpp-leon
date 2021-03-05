// https://leetcode.com/problems/intersection-of-two-linked-lists/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49799/Simple-C%2B%2B-solution-(5-lines)
#include <cstddef>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA, *curB = headB;

        while (curA != curB)
        {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }

        return curA;
    }
};