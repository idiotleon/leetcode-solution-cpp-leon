// https://leetcode.com/problems/number-of-1-bits/
//
// Time Complexity:     O(`n`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/number-of-1-bits/discuss/55255/C%2B%2B-Solution%3A-n-and-(n-1)
#include <stdint.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        while (n)
        {
            n &= (n - 1);
            ++count;
        }

        return count;
    }
};