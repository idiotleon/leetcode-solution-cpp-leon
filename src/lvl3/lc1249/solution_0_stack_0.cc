// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(`kLen`)
//
// Reference:
//  https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/419402/JavaC++-Stack/524035
#include <string>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        const int kLen = s.size();

        int open = 0;
        for (int i = 0; i < kLen; ++i)
        {
            if (s[i] == OPEN)
            {
                ++open;
            }
            else if (s[i] == CLOSED)
            {
                --open;
            }

            if (open < 0)
            {
                s[i] = PLACE_HOLDER;
                ++open;
            }
        }

        int closed = 0;
        for (int i = kLen - 1; i >= 0; --i)
        {
            if (s[i] == OPEN)
            {
                --closed;
            }
            else if (s[i] == CLOSED)
            {
                ++closed;
            }

            if (closed < 0)
            {
                s[i] = PLACE_HOLDER;
                ++closed;
            }
        }

        s.erase(remove(s.begin(), s.end(), PLACE_HOLDER), s.end());
        return s;
    }

private:
    const char OPEN = '(', CLOSED = ')', PLACE_HOLDER = '#';
};