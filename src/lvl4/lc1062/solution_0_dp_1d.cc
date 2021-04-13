// https://leetcode.com/problems/longest-repeating-substring/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/longest-repeating-substring/discuss/318629/DP-solution-O(n2)-time-O(n)-spaces
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestRepeatingSubstring(string str)
    {
        const int kLenS = str.size();
        vector<int> dp(kLenS + 1, 0);

        int longest = 0;

        for (int hi = 0; hi <= kLenS; ++hi)
        {
            for (int lo = hi - 1; lo >= 0; --lo)
            {
                if (str[lo] == str[hi])
                {
                    dp[lo + 1] = 1 + dp[lo];
                }
                else
                {
                    dp[lo + 1] = 0;
                }

                longest = max(longest, dp[lo]);
            }
        }

        return longest;
    }
};