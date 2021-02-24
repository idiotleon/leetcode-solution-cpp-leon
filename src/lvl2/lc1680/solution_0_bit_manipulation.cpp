// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/discuss/961350/C%2B%2B-O(N)-time-iterative
class Solution
{
public:
    int ConcatenatedBinary(int n)
    {
        long ans = 0, len = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((i & (i - 1)) == 0)
                ++len;
            ans = ((ans << len) % kMod + i) % kMod;
        }

        return ans;
    }

private:
    const int kMod = (int)1e9 + 7;
};