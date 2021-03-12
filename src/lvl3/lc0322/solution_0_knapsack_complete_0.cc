// https://leetcode.com/problems/coin-change/
//
// Time Complexity:     O(`kRange` * `kSize`)
// Space Complexity:    O(`kRange` * `kSize`)
//
// Reference:
//  https://leetcode.com/problems/coin-change/discuss/77360/C++-O(n*amount)-time-O(amount)-space-DP-solution/81406
//  https://leetcode.com/problems/coin-change/discuss/77360/C++-O(n*amount)-time-O(amount)-space-DP-solution/81414
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int CoinChange(vector<int> &coins, int amount)
    {
        const int kRange = 1 + amount;

        vector<int> dp(kRange, kRange);
        dp[0] = 0;

        for (int &coin : coins)
        {
            for (int val = coin; val <= amount; ++val)
            {
                dp[val] = min(dp[val], 1 + dp[val - coin]);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};