// https://leetcode.com/problems/palindrome-linked-list/
//
// Time Complexity:     O(L)
// Space Complexity:    O(L)
//
// Reference:
//  https://leetcode.com/problems/palindrome-linked-list/discuss/64490/My-easy-understand-C++-solution/66127
//  https://leetcode.com/problems/palindrome-linked-list/discuss/64490/My-easy-understand-C%2B%2B-solution
#include "list_node.h"

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        return dfs(head, head);
    }

private:
    bool dfs(ListNode *&head, ListNode *cur)
    {
        if (!cur)
            return true;

        bool isPal = dfs(head, cur->next);

        if (head->val != cur->val)
            return false;

        head = head->next;
        return isPal;
    }
};