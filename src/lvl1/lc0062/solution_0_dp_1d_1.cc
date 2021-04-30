// https://leetcode.com/problems/unique-paths/
//
// Time Complexity:     O(`m` * `n`)
// Space Complexity:    O(`n`)
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
        vector<int> prev(n, 1), cur(n, 1);

        for (int row = 1; row < m; ++row)
        {
            for (int col = 1; col < n; ++col)
            {
                cur[col] = prev[col] + cur[col - 1];
            }

            swap(prev, cur);
        }

        return prev[n - 1];
    }
};