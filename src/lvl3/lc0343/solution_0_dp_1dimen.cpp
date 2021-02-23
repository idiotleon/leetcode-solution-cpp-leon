// https://leetcode.com/problems/integer-break/
//
// Time Complexity:     O(`n` ^ 2)
// Space Complexity:    O(`n`)
//
// Reference:
//  https://leetcode.com/problems/integer-break/discuss/80772/C%2B%2B-dynamic-programming-solution
//  https://www.cnblogs.com/grandyang/p/5411919.html
//  https://leetcode.com/problems/integer-break/discuss/80772/C%2B%2B-dynamic-programming-solution
#include <vector>

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 2)
            return 1;

        vector<int> dp(n + 1, 0);

        dp[1] = 1;

        for (int hi = 2; hi <= n; ++hi)
        {
            for (int lo = 1; lo <= hi / 2; ++lo)
            {
                dp[hi] = max(dp[hi], max(lo * (hi - lo), lo * dp[hi - lo]));
            }
        }

        return dp[n];
    }
};