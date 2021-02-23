// https://leetcode.com/problems/integer-break/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://www.cnblogs.com/grandyang/p/5411919.html
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2 || n == 3)
            return n - 1;

        int ans = 1;

        while (n > 4)
        {
            ans *= 3;
            n -= 3;
        }

        return ans * n;
    }
};