// @author: Leon
// https://leetcode.com/problems/palindrome-linked-list/
//
// Time Complexity:     O(2 * L) ~ O(L)
// Space Complexity:    O(L)
#include <stack>
#include "list_node.h"

using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> stack;

        ListNode *cur = head;

        while (cur)
        {
            stack.push(cur->val);
            cur = cur->next;
        }

        cur = head;

        while (stack.size() > 1)
        {
            if (cur->val != stack.top())
                return false;

            stack.pop();
            cur = cur->next;
        }

        return true;
    }
};