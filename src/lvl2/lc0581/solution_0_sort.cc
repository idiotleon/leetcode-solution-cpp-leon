// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//
// Time Complexity:     O(`kSize` * log(`kSize`))
// Space Complexity:    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103062/C%2B%2B-Clean-Code-2-Solution-Sort-O(NlgN)-and-max-min-vectors-O(N)
#include <vector>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        const int kSize = nums.size();

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int lo = 0, hi = kSize - 1;
        while (lo < kSize && nums[lo] == sorted[lo])
            ++lo;

        while (lo < hi && nums[hi] == sorted[hi])
            --hi;

        return hi + 1 - lo;
    }
};