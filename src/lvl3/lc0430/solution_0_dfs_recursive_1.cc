// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/295912/C%2B%2B-Simple-5-line-recursive-solution-(with-diagram)
#include "node.h"

using namespace std;

class Solution
{
public:
    Node *flatten(Node *head)
    {
        return DFS(head, nullptr);
    }

private:
    Node *DFS(Node *head, Node *tail)
    {
        if (!head)
            return tail;
        head->next = DFS(head->child, DFS(head->next, tail));
        if (head->next)
            head->next->prev = head;
        head->child = nullptr;
        return head;
    }
};