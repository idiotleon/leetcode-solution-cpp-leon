// https://leetcode.com/problems/find-the-celebrity/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//https://leetcode.com/problems/find-the-celebrity/discuss/71268/Straight-forward-C%2B%2B-solution-with-explaination
#include "KnowsAPI.h"

class Solution
{
public:
    int findCelebrity(int n)
    {
        if (n <= 1)
            return n;

        int celebrity = 0;
        for (int i = 1; i < n; ++i)
        {
            if (!knows(i, celebrity))
            {
                celebrity = i;
            }
        }

        for (int j = 0; j < n; ++j)
        {
            if (j == celebrity)
                continue;

            if (!knows(j, celebrity) || knows(celebrity, j))
            {
                return -1;
            }
        }

        return celebrity;
    }
};