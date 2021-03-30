#include <vector>

using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
            return 0;
        const int kSize = envelopes.size();

        sort(envelopes.begin(), envelopes.end());

        vector<int> dp(kSize, 1);

        for (int hi = 0; hi < kSize; ++hi)
        {
            for (int lo = 0; lo < hi; ++lo)
            {
                if (envelopes[lo][0] < envelopes[hi][0] && envelopes[lo][1] < envelopes[hi][1])
                    dp[hi] = max(dp[hi], 1 + dp[lo]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};