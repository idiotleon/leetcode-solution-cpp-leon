// https://leetcode.com/problems/regular-expression-matching/
//
// Time Complexity:     O(`kLenS` * `kLenP`)
// Space Complexity:    O(`kLenS` * `kLenP`)
//
// Reference:
//  https://leetcode.com/problems/regular-expression-matching/discuss/5684/C++-O(n)-space-DP/6792
//  https://leetcode.com/problems/regular-expression-matching/discuss/5684/C%2B%2B-O(n)-space-DP
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        const int kLenS = s.size(), kLenP = p.size();

        vector<vector<bool>> dp(kLenS + 1, vector<bool>(kLenP + 1, false));

        dp[0][0] = true;

        for (int idxS = 0; idxS <= kLenS; ++idxS)
        {
            for (int idxP = 1; idxP <= kLenP; ++idxP)
            {
                if (p[idxP - 1] != '*')
                {
                    dp[idxS][idxP] = idxS > 0 && dp[idxS - 1][idxP - 1] && (s[idxS - 1] == p[idxP - 1] || p[idxP - 1] == '.');
                }
                else
                {
                    dp[idxS][idxP] = dp[idxS][idxP - 2] || (idxS > 0 && dp[idxS - 1][idxP] && (s[idxS - 1] == p[idxP - 2] || p[idxP - 2] == '.'));
                }
            }
        }

        return dp[kLenS][kLenP];
    }
};