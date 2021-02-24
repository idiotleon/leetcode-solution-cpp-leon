// https://leetcode.com/problems/arithmetic-slices/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/arithmetic-slices/discuss/90093/3ms-C++-Standard-DP-Solution-with-Very-Detailed-Explanation/94649
//  https://leetcode.com/problems/arithmetic-slices/discuss/90093/3ms-C%2B%2B-Standard-DP-Solution-with-Very-Detailed-Explanation
//  https://leetcode.com/problems/arithmetic-slices/discuss/215861/Detailed-Explanation:-Two-DP-Solutions/283839
#include <vector>

using namespace std;

class Solution
{
public:
    int NumberOfArithmeticSlices(vector<int> &nums)
    {
        const int kSize = nums.size();
        if (kSize <= 2)
            return 0;

        int len = 0, count = 0;
        for (int i = 2; i < kSize; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                ++len;
            }
            else
            {
                len = 0;
            }

            count += len;
        }

        return count;
    }
};