// https://leetcode.com/problems/combination-sum-iv/
//
// Time Complexity:     O(`kRange` * `kSize`)
// Space Complexity:    O(`kRange`)
//
// Reference:
//  https://leetcode.com/problems/combination-sum-iv/discuss/85036/1ms-Java-DP-Solution-with-Detailed-Explanation
//  https://leetcode.com/problems/combination-sum-iv/discuss/85120/C%2B%2B-template-for-ALL-Combination-Problem-Set
#include <vector>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        const int kRangeSum = 1 + target;
        // not used
        // const int kSize = nums.size();

        vector<unsigned int> dp(kRangeSum, 0);
        dp[0] = 1;

        for (int sum = 1; sum < kRangeSum; ++sum)
        {
            for (int num : nums)
            {
                if (sum - num >= 0)
                {
                    dp[sum] += dp[sum - num];
                }
            }
        }

        return dp[target];
    }
};