// https://leetcode.com/problems/unique-paths/
//
// Time Complexity:     O(`m` * `n`)
// Space Complexity:    O(`m` * `n`)
//
// Reference:
//  https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int row = 1; row < m; ++row)
        {
            for (int col = 1; col < n; ++col)
            {
                dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
            }
        }

        return dp[m - 1][n - 1];
    }
};