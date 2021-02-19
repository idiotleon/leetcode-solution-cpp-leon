// https://leetcode.com/problems/arithmetic-slices/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/arithmetic-slices/discuss/90093/3ms-C%2B%2B-Standard-DP-Solution-with-Very-Detailed-Explanation
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        const int kSize = nums.size();
        if (kSize < 3)
            return 0;

        vector<int> dp(kSize, 0);

        int count = 0;

        for (int i = 2; i < kSize; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = 1 + dp[i - 1];
            }

            count += dp[i];
        }

        return count;
    }
};