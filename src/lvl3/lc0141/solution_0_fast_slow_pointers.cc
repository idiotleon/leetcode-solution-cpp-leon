// https://leetcode.com/problems/linked-list-cycle/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/linked-list-cycle/discuss/44690/My-easy-12ms-C%2B%2B-solution-sharing.
#include "list_node.h"

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast;
        fast = head;

        while (head)
        {
            head = head->next;

            if (fast->next && fast->next->next)
            {
                fast = fast->next->next;
            }
            else
            {
                return false;
            }

            if (fast == head)
                return true;
        }

        return false;
    }
};