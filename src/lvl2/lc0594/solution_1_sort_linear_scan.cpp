// https://leetcode.com/problems/longest-harmonious-subsequence/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/longest-harmonious-subsequence/discuss/103499/Three-C%2B%2B-Solution-run-time-with-explanation
#include <vector>

using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        const int nNums = nums.size();
        sort(nums.begin(), nums.end());

        int longest = 0;

        int prev_start = 0, cur_start = 0;

        for (int i = 1; i < nNums; ++i)
        {
            if (nums[i] - nums[prev_start] > 1)
                prev_start = cur_start;

            if (nums[i] != nums[i - 1])
                cur_start = i;

            if (nums[i] - nums[prev_start] == 1)
                longest = max(longest, i - prev_start + 1);
        }

        return longest;
    }
};