// https://leetcode.com/problems/number-of-1-bits/
//
// Time Complexity:     O(`n`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/number-of-1-bits/discuss/55255/C++-Solution:-n-and-(n-1)/837297
#include <stdint.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n > 0)
        {
            if ((n & 1) > 0)
            {
                ++count;
            }

            n = n >> 1;
        }

        return count;
    }
};