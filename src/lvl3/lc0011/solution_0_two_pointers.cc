// https://leetcode.com/problems/container-with-most-water/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/container-with-most-water/discuss/6090/Simple-and-fast-C%2B%2BC-with-explanation
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        const int kSize = heights.size();

        int water = 0;
        int lo = 0, hi = kSize - 1;

        while (lo < hi)
        {
            const int kHeight = min(heights[lo], heights[hi]);
            water = max(water, (hi - lo) * kHeight);

            while (lo < hi && heights[lo] <= kHeight)
                ++lo;
            while (lo < hi && heights[hi] <= kHeight)
                --hi;
        }

        return water;
    }
};