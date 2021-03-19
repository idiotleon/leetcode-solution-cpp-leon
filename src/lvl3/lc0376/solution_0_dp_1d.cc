// https://leetcode.com/problems/wiggle-subsequence/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/wiggle-subsequence/discuss/84887/C%2B%2B-0ms-O(N)-dynamic-programming-solution
#include <vector>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        const int kSize = nums.size();

        if (kSize == 0)
            return 0;

        vector<int> up(kSize, 0);
        vector<int> down(kSize, 0);
        up[0] = 1;
        down[0] = 1;

        for (int i = 1; i < kSize; ++i)
        {
            if (nums[i - 1] < nums[i])
            {
                up[i] = 1 + down[i - 1];
                down[i] = down[i - 1];
            }
            else if (nums[i - 1] > nums[i])
            {
                up[i] = up[i - 1];
                down[i] = 1 + up[i - 1];
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }

        return max(up[kSize - 1], down[kSize - 1]);
    }
};