// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108867/C++-concise-solution-O(n)-time-O(1)-space/113825
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        const int kSize = prices.size();

        int hold = -prices[0], sold = 0;

        for (int i = 1; i < kSize; ++i)
        {
            hold = max(hold, sold - prices[i]);
            sold = max(sold, hold + prices[i] - fee);
        }

        return sold;
    }
};