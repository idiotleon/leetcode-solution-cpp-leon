// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(`kLen`)
//
// Reference:
//  https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/419402/JavaC%2B%2B-Stack
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        const int kLen = s.size();
        stack<int> st;

        for (auto i = 0; i < kLen; ++i)
        {
            if (s[i] == OPEN)
                st.push(i);
            else if (s[i] == CLOSED)
            {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = PLACE_HOLDER;
            }
        }

        while (!st.empty())
        {
            s[st.top()] = PLACE_HOLDER;
            st.pop();
        }

        s.erase(remove(s.begin(), s.end(), PLACE_HOLDER), s.end());
        return s;
    }

private:
    const char OPEN = '(', CLOSED = ')', PLACE_HOLDER = '#';
};