// https://leetcode.com/problems/longest-valid-parentheses/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(`kLen`)
//
// `dp[i]` refers to the longest length till index `i` (of the `str`)
//
// Reference:
//  https://leetcode.com/problems/longest-valid-parentheses/discuss/14133/My-DP-O(n)-solution-without-using-stack
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string str)
    {
        const int kLen = str.size();
        if (kLen <= 1)
            return 0;

        vector<int> dp(kLen, 0);
        int longest = 0;

        for (int i = 1; i < kLen; ++i)
        {
            if (str[i] == kClosedParen)
            {
                if (str[i - 1] == kOpenParen) // to look 1 step back
                {
                    // to look 2 steps back
                    dp[i] = (i - 2) >= 0 ? (dp[i - 2] + 2) : 2;
                    longest = max(dp[i], longest);
                }
                else
                {
                    // the start index of the substring referred to
                    // to look 1 step back
                    const int kStartIdx = i - dp[i - 1] - 1;
                    // pretty similar with the former `if{}`
                    if (kStartIdx >= 0 && str[kStartIdx] == kOpenParen) // if the index is itself valid, and a valid start of "(..."
                    {
                        // to look 2 steps back
                        dp[i] = dp[i - 1] + 2 + (kStartIdx - 1 >= 0 ? dp[kStartIdx - 1] : 0);
                        longest = max(longest, dp[i]);
                    }
                }
            }
            // to skip the rest, due to `dp[i]` always being 0 when it is a `(`
        }

        return longest;
    }

private:
    const char kOpenParen = '(';
    const char kClosedParen = ')';
};