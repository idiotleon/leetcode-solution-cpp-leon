// https://leetcode.com/problems/furthest-building-you-can-reach/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/furthest-building-you-can-reach/discuss/918515/JavaC%2B%2BPython-Priority-Queue
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        const int kSize = heights.size();
        priority_queue<int> min_heap;

        for (int i = 0; i < kSize - 1; ++i)
        {
            const int kDiff = heights[i + 1] - heights[i];

            if (kDiff > 0)
                min_heap.push(-kDiff);

            if (min_heap.size() > ladders)
            {
                bricks += min_heap.top();
                min_heap.pop();
            }

            if (bricks < 0)
                return i;
        }

        return kSize - 1;
    }
};