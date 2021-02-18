// https://leetcode.com/problems/container-with-most-water/
//
// Time Complexity:     O()
// Space Complexity:    O()
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
        const int nHeights = heights.size();

        int water = 0;
        int lo = 0, hi = nHeights - 1;

        while (lo < hi)
        {
            int height = min(heights[lo], heights[hi]);
            water = max(water, (hi - lo) * height);

            while (heights[lo] <= height && lo < hi)
                ++lo;
            while (heights[hi] <= height && lo < hi)
                --hi;
        }

        return water;
    }
};