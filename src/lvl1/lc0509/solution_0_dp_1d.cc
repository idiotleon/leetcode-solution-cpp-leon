// @author: Leon
// https://leetcode.com/problems/fibonacci-number/
//
// Time Complexity:     O(`n`)
// Space Complexity:    O(1)
#include <vector>

using namespace std;

class Solution
{
public:
    int Fib(int n)
    {
        if (n < 1)
            return 0;
        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};