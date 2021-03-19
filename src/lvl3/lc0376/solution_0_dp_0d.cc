// https://leetcode.com/problems/wiggle-subsequence/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/wiggle-subsequence/discuss/84887/C++-0ms-O(N)-dynamic-programming-solution/89589
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

        int up = 1, down = 1;

        for (int i = 1; i < kSize; ++i)
        {
            if (nums[i - 1] < nums[i])
            {
                up = 1 + down;
            }
            else if (nums[i - 1] > nums[i])
            {
                down = 1 + up;
            }
        }

        return max(up, down);
    }
};