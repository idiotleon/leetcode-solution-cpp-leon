// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//
// Time Complexity:     O(lg(`kNums`))
// Space Complexity:    O(1)
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> SearchRange(vector<int> &nums, int target)
    {
        const int kSize = nums.size();
        int first_pos = LowerBound(nums, target);

        if (first_pos == kSize || nums[first_pos] != target)
            return vector<int>{-1, -1};

        int last_pos = LowerBound(nums, 1 + target) - 1;

        return vector<int>{first_pos, last_pos};
    }

private:
    int LowerBound(vector<int> &nums, int target)
    {
        const int kNums = nums.size();

        int lo = 0, hi = kNums;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (target > nums[mid])
                lo = 1 + mid;
            else
                hi = mid;
        }

        return lo;
    }
};