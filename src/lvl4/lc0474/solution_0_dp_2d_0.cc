// https://leetcode.com/problems/ones-and-zeroes/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/ones-and-zeroes/discuss/95814/c%2B%2B-DP-solution-with-comments
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
            int cnt_zero = 0, cnt_one = 0;

            for (auto &ch : str)
            {
                if (ch == '0')
                    ++cnt_zero;
                else if (ch == '1')
                    ++cnt_one;
            }

            for (int i = m; i >= cnt_zero; --i)
            {
                for (int j = n; j >= cnt_one; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - cnt_zero][j - cnt_one] + 1);
                }
            }
        }

        return dp[m][n];
    }
};