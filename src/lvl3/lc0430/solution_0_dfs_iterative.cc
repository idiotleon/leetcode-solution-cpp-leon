// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/152066/c++-about-10-lines-solution/205824
#include <cstddef>
#include <stack>
#include "node.h"

using namespace std;

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return NULL;
        stack<Node *> stack;
        stack.push(head);

        Node *cur = NULL, *prev = NULL, *new_head = NULL;

        while (!stack.empty())
        {
            prev = cur;
            cur = stack.top();
            stack.pop();

            if (cur->next)
                stack.push(cur->next);

            if (cur->child)
                stack.push(cur->child);

            cur->child = NULL;
            cur->prev = prev;

            if (prev)
                prev->next = cur;
            else
                new_head = cur;
        }

        return new_head;
    }
};