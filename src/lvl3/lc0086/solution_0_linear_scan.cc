// https://leetcode.com/problems/partition-list/
//
// Time Complexity:     O(L)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution
#include "list_node.h"

using namespace std;

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // dummy head for the less
        ListNode dummy_less(0);
        // dummy head for the greater
        ListNode dummy_greater(0);

        // (prev) cursor for the less
        ListNode *prev_less = &dummy_less;
        // (prev) cursor for the greater
        ListNode *prev_greater = &dummy_greater;
        // (current) cursor
        ListNode *cur = head;

        while (cur)
        {
            if (cur->val < x)
            {
                prev_less->next = cur;
                prev_less = prev_less->next;
            }
            else
            {
                prev_greater->next = cur;
                prev_greater = prev_greater->next;
            }

            cur = cur->next;
        }

        prev_greater->next = nullptr;
        prev_less->next = dummy_greater.next;
        return dummy_less.next;
    }
};