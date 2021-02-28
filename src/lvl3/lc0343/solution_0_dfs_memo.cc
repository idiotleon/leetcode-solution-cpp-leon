// https://leetcode.com/problems/integer-break/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/integer-break/discuss/697437/Java-DP-and-DFS-%2B-MEMO
#include <vector>

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 2)
            return 1;
        if (n == 3)
            return 2;

        vector<int> memo(n + 1, kNotVisited);

        return dfs(n, memo);
    }

private:
    const int kNotVisited = -1;
    int dfs(int n, vector<int> &memo)
    {
        if (n <= 3)
            return n;
        if (memo[n] != kNotVisited)
            return memo[n];

        memo[n] = 0;
        for (int i = 1; i <= n / 2; ++i)
        {
            memo[n] = max(memo[n], dfs(n - i, memo) * dfs(i, memo));
        }

        return memo[n];
    }
};