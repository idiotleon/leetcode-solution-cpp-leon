// https://leetcode.com/problems/coin-change/
//
// Time Complexity:     O(`kRange` * `kSize`)
// Space Complexity:    O(`kRange` * `kSize`)
//
// Reference:
//  https://leetcode.com/problems/coin-change/discuss/77360/C%2B%2B-O(n*amount)-time-O(amount)-space-DP-solution
#include <vector>

using namespace std;

class Solution
{
public:
    int CoinChange(vector<int> &coins, int amount)
    {
        const int kSize = coins.size();
        const int kRange = 1 + amount;

        vector<int> dp(kRange, kRange);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < kSize; ++j)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};