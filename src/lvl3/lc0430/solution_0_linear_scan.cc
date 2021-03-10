// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
//
// Time Complexity:     O(N)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/152066/c++-about-10-lines-solution/430138
//  https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/152066/c%2B%2B-about-10-lines-solution
#include <cstddef>
#include "node.h"

class Solution
{
public:
    Node *flatten(Node *head)
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            if (cur->child)
            {
                Node *next = cur->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;

                Node *p = cur->next;
                while (p->next)
                    p = p->next;

                p->next = next;

                if (next)
                    next->prev = p;
            }
        }

        return head;
    }
};