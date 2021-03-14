// https://leetcode.com/problems/binary-trees-with-factors/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/binary-trees-with-factors/discuss/125794/C%2B%2BJavaPython-DP-solution
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        const long kMod = pow(10, 9) + 7;
        const int kLen = arr.size();
        sort(arr.begin(), arr.end());

        long ans = 0;

        unordered_map<int, long> dp;
        for (int hi = 0; hi < kLen; ++hi)
        {
            dp[arr[hi]] = 1;

            for (int lo = 0; lo < hi; ++lo)
            {
                if (arr[hi] % arr[lo] == 0)
                    dp[arr[hi]] = (dp[arr[hi]] + dp[arr[lo]] * dp[arr[hi] / arr[lo]]) % kMod;
            }

            ans = (ans + dp[arr[hi]]) % kMod;
        }

        return ans;
    }
};