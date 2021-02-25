// https://leetcode.com/problems/score-of-parentheses/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/score-of-parentheses/discuss/141777/C%2B%2BJavaPython-O(1)-Space
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string str)
    {
        stack<int> stk;

        int cur = 0;
        for (char ch : str)
        {
            if (ch == kOpenParen)
            {
                stk.push(cur);
                cur = 0;
            }
            else
            {
                cur += stk.top() + max(cur, 1);
                stk.pop();
            }
        }

        return cur;
    }

private:
    const char kOpenParen = '(';
};