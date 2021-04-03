// https://leetcode.com/problems/ones-and-zeroes/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/ones-and-zeroes/discuss/95814/c++-DP-solution-with-comments/100382
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &str : strs)
        {
            const int kLen = str.size();

            const int kOnes = count(str.begin(), str.end(), '1');
            const int kZeros = kLen - kOnes;

            for (int i = m; i >= kZeros; --i)
            {
                for (int j = n; j >= kOnes; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - kZeros][j - kOnes] + 1);
                }
            }
        }

        return dp[m][n];
    }
};