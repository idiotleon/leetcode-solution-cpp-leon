// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/discuss/1034231/C%2B%2B-Simple-and-Easy-Solution-faster-than-99
#include <vector>

using namespace std;

class Solution
{
public:
    bool KLengthApart(vector<int> &nums, int k)
    {
        const int kSize = nums.size();
        int prev_one = -k - 1;

        for (int i = 0; i < kSize; ++i)
        {
            if (nums[i])
            {
                if (i - prev_one <= k)
                    return false;
                prev_one = i;
            }
        }

        return true;
    }
};