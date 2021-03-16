// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://www.youtube.com/watch?v=CBvPujbmWhU
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int held = -prices[0], sold = 0;

        for (auto &price : prices)
        {
            const int kPrevHeld = held;
            const int kPreSold = sold;
            held = max(kPrevHeld, kPreSold - price);
            sold = max(kPreSold, kPrevHeld + price - fee);
        }

        return sold;
    }
};