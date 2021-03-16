// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//
// Time Complexity:     O(`kSize`)
// Space Complexity;    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        const int kSize = prices.size();
        if (kSize <= 1)
            return 0;

        vector<int> hold(kSize, 0);
        hold[0] = -prices[0] - fee;

        vector<int> sold(kSize, 0);

        for (int i = 1; i < kSize; ++i)
        {
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i] - fee);
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i]);
        }

        return sold[kSize - 1];
    }
};