// https://leetcode.com/problems/non-decreasing-array/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/non-decreasing-array/discuss/106826/JavaC%2B%2B-Simple-greedy-like-solution-with-explanations
#include <vector>

using namespace std;

class Solution
{
public:
    bool CheckPossibility(vector<int> &nums)
    {
        const int kSize = nums.size();
        int cnt = 0;

        for (int i = 1; i < kSize && cnt <= 1; ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                ++cnt;
                if (i - 2 < 0 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        }

        return cnt <= 1;
    }
};