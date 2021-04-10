// @author: Leon
// https://leetcode.com/problems/longest-common-subsequence/
//
// Time Complexity:     O(`kLen1` * `kLen2`)
// Space Complexity:    O(`kLen1` * `kLen2`)
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        const int kLen1 = text1.size(), kLen2 = text2.size();

        vector<vector<int>> dp(kLen1 + 1, vector<int>(kLen2 + 1, 0));

        int longest = 0;

        for (int idx1 = 0; idx1 < kLen1; ++idx1)
        {
            for (int idx2 = 0; idx2 < kLen2; ++idx2)
            {
                if (text1[idx1] == text2[idx2])
                {
                    dp[1 + idx1][1 + idx2] = max(dp[1 + idx1][1 + idx2], 1 + dp[idx1][idx2]);
                }
                else
                {
                    dp[1 + idx1][1 + idx2] = max(dp[1 + idx1][idx2], dp[idx1][1 + idx2]);
                }

                longest = max(longest, dp[idx1 + 1][idx2 + 1]);
            }
        }

        return longest;
    }
};